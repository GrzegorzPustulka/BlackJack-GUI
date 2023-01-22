#ifndef CROUPIER_H
#define CROUPIER_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Deck.h"

class Croupier: public Deck, public QMainWindow
{
private:
    int how_many_as;

protected:
    std::vector<QString> handCroupier;

public:

    Croupier();
    ~Croupier();
    int getHowManyAs() { return this->how_many_as; };
    void setHowManyAs(int how_many_as) { this->how_many_as = how_many_as; };
    void howManyAs(int how_many_as) { this->how_many_as = how_many_as; };
    /**
     * @brief Dodaje określoną liczbę kart do ręki krupiera.
     * Funkcja dodaje podaną liczbę kart z talii do ręki krupiera i usuwa je z talii. Jeśli w talii nie ma wystarczającej liczby kart,
     * wyrzuca wyjątek std::logic_error z odpowiednim komunikatem.
     * @param count Liczba kart do dodania.
     * @param decks wskaźnik na obiekt decks
     * @throws std::logic_error Jeśli w talii nie ma wystarczającej liczby kart.
     */
    void addCards(int count, Deck* decks);
    /**
     * @brief Wyświetla określoną liczbę kart z ręki krupiera.
     * Funkcja wyświetla na standardowym wyjściu określoną liczbę kart z ręki krupiera.
     * @param count Liczba kart do wyświetlenia.
     * @param decks wskaźnik na obiekt decks
     */
    void showHandDeck(int count,Ui::MainWindow *ui);
    /**
     * @brief Oblicza liczbę punktów w kartach krupiera.
     * Funkcja przelatuje przez całą talię krupiera i na podstawie nazw kart przypisuje im odpowiednią liczbę punktów.
     * W przypadku Asów, funkcja domyślnie przypisuje im wartość 11 punktów, ale jeśli ogólna liczba punktów przekroczy 21,
     * to Asy są traktowane jako 1 punkt, aby zmniejszyć liczbę punktów do 21 lub mniej.
     * @return Liczba punktów w kartach krupiera.
     */
    int countPoints();
    /**
     * @brief Określa ile kart należy dodać krupierowi, aby jego punktacja była większa od 16.
     * @param decks Wskaźnik na talię z której karty będą pobierane.
     * @return Liczba kart, które należy dodać krupierowi.
     */
    int lessOrMore(Deck* decks);
    /**
     * @brief Sprawdza czy krupier ma asa na ręce.
     * Metoda sprawdza czy krupier ma asa na ręce. Jeśli tak, zwraca wartość true,
     * w przeciwnym wypadku zwraca wartość false.
     * @return Wartość true, jeśli krupier ma asa, w przeciwnym wypadku wartość false.
     */
    bool checkInsurance();
    /**
     * @brief Czyści zawartość kontenera z kartami Krupiera
     */
    void clearHand();
    /**
     * @brief Wypisuje informację o odchodzeniu krupiera od stolu.
     *
     * Metoda wypisuje na standardowe wyjście informację o odchodzeniu krupiera od stolu.
     * Wypisana zostaje nazwa krupiera.
     */
    void goodbay();
    /**
     * @brief Zwraca liczbę kart w ręce krupiera.
     * @return Liczba kart w ręce krupiera.
     */
    int howManyCardsInHand();
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
#endif // CROUPIER_H
