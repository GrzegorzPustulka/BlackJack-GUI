#ifndef DECK_H
#define DECK_H
#include <QMainWindow>
#include <iostream>
#include <vector>
#include <map>
#include <QPixmap>
#include <algorithm>
#include <random>

class Deck
{
private:
    std::vector<QString> primaryDeck;
    int howManyDeck;

public:
    std::vector<QString> deck;
    std::map<QString, int> deckPoint;
    std::map<QString, QPixmap> photos;
    /**
     * @brief Konstruktor domyślny talii kart.
     * Talia składa się z od 1 do 8 talii standardowych 52-kartowych talii
     * (zawierających po jednej kopii każdej z możliwych kart).
     * Talie są losowo tasowane po utworzeniu za pomocą funkcji shuffle().
     */
    Deck();
    ~Deck();
    /**
     * @brief Tworzy talie kart do gry
     * Talia składa się z od 1 do 8 talii standardowych 52-kartowych talii
     * (zawierających po jednej kopii każdej z możliwych kart).
     */
    void createDeck();
    /**
     * @brief Usuwa określoną liczbę kart z talii.
     * Metoda usuwa podaną liczbę kart z początku talii.
     * @param count Liczba kart do usunięcia.
     */
    void removeCardsFromDeck(int count);
    /**
    * @brief Miesza karty w talii.
    * Funkcja miesza karty w talii za pomocą algorytmu std::shuffle() z biblioteki STL.
    */
    void shuffle();
    /**
     * @brief Zwraca liczbę kart w talii.
     * Funkcja zwraca liczbę kart w talii, obliczaną jako rozmiar wewnętrznego wektora deck.
     * @return Liczba kart w talii.
     */
    size_t howManyCards();
};

#endif // DECK_H
