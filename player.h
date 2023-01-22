#ifndef PLAYER_H
#define PLAYER_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Deck.h"
#include <fstream>
#include <QPixmap>
#include <map>
#include <QMessageBox>

class Player: public Deck, public QMainWindow
{
private:
    std::vector<QString> handPlayer;
    void initMoney();
    int startMoney;
    int currentlyMoney;
    int moneyOnBet;
    int how_many_as;
public:
    Player();
    ~Player();

    int getStartMoney() { return this->startMoney; };
    void setStartMoney(int startMoney) { this->startMoney=startMoney; };
    int getCurrentlyMoney() { return this->currentlyMoney; };
    void setCurrentlyMoney(int currentlyMoney) { this->currentlyMoney = currentlyMoney; };
    int getMoneyOnBet() { return this->moneyOnBet; };
    void setMoneyOnBet(int moneyOnBet) { this->moneyOnBet = moneyOnBet; };
    int getHowManyAs() { return this->how_many_as; };
    void setHowManyAs(int how_many_as) { this->how_many_as = how_many_as; };

    /**
     * @brief Dodaje określoną liczbę kart do ręki gracza.
     * Funkcja dodaje podaną liczbę kart z talii do ręki gracza i usuwa je z talii. Jeśli w talii nie ma wystarczającej liczby kart,
     * wyrzuca wyjątek std::logic_error z odpowiednim komunikatem.
     * @param count Liczba kart do dodania.
     * @param decks wskaźnik na obiekt decks
     * @throws std::logic_error Jeśli w talii nie ma wystarczającej liczby kart.
     */
    void addCards(int count, Deck* decks);
    /**
     * @brief Wyświetla określoną liczbę kart z ręki gracza.
     * Funkcja wyświetla na standardowym wyjściu określoną liczbę kart z ręki gracza.
     * @param count Liczba kart do wyświetlenia.
     * @param decks wskaźnik na obiekt decks
     */
    void showHandDeck(int count, Ui::MainWindow *ui);
    /**
     * @brief Oblicza liczbę punktów w kartach gracza.
     * Funkcja przelatuje przez całą talię gracza i na podstawie nazw kart przypisuje im odpowiednią liczbę punktów.
     * W przypadku Asów, funkcja domyślnie przypisuje im wartość 11 punktów, ale jeśli ogólna liczba punktów przekroczy 21,
     * to Asy są traktowane jako 1 punkt, aby zmniejszyć liczbę punktów do 21 lub mniej.
     * @return Liczba punktów w kartach gracza.
     */
    int countPoints();
    /**
     * @brief Gracz obstawia określoną kwotę pieniędzy
     * Gracz wybiera kwotę pieniędzy, którą chce postawić. Musi być to liczba podzielna przez 10.
     * Jeśli gracz próbuje postawić więcej pieniędzy niż posiada, zostaje wyrzucony z gry.
     * @pre Gracz posiada przynajmniej 10 jednostek monetarnej jednostki.
     * @post Gracz traci postawioną kwotę pieniędzy.
     * @exception exit(1) Gracz próbuje oszukać krupiera lub próbuje postawić więcej pieniędzy niż posiada.
     */
    void bet(int money, Ui::MainWindow *ui);
    /**
     * @brief Czyści zawartość kontenera z kartami gracza
     */
    void clearHand();
    /**
     * @brief Kończy grę w przypadku braku środków finansowych gracza
     * @param money Obecne środki finansowe gracza
     */
    void gameOver(int money);
    /**
     * @brief Wypisuje informację o odchodzeniu gracza od stolu.
     *
     * Metoda wypisuje na standardowe wyjście informację o odchodzeniu gracza od stolu.
     * Wypisana zostaje nazwa gracza.
     */
    void goodbay();
    /**
     * @brief Zwraca liczbę kart w ręce gracza.
     * @return Liczba kart w ręce gracza.
     */
    size_t howManyCardsInHand();
    /**
     * @brief Operator [] dla klasy Player
     *
     * @param idx Indeks (string)
     * @return Wartość startMoney lub currentlyMoney w zależności od wartości idx
     * @throw Wyjątek, jeśli idx nie jest równe "startMoney", "start", "currentlyMoney" lub "end" i zamyka program z błedem 1
     */
    int operator[](std::string idx);

    /**
     * @brief Sprawdza, czy łańcuch znaków jest podciągiem innego łańcucha.
     * Funkcja szablonowa sprawdza, czy podany łańcuch znaków @p needle jest podciągiem innego łańcucha @p haystack.
     * Używa funkcji std::basic_string::find() z biblioteki STL do wyszukiwania podciągu.
     * @tparam T Typ znaków łańcucha (może być dowolny typ charakterystyczny).
     * @param haystack Łańcuch, w którym szukamy podciągu.
     * @param needle Szukany podciąg.
     * @return @c true, jeśli @p needle jest podciągiem @p haystack, @c false w przeciwnym razie.
     */
    template<class T>
    bool IsSubstring(const std::basic_string<T>& haystack, const T* needle)
    {
        return haystack.find(needle) != std::basic_string<T>::npos;
    }
};

#endif // PLAYER_H
