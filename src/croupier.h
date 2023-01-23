#ifndef CROUPIER_H
#define CROUPIER_H
#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Deck.h"
#include <QMessageBox>

class Croupier: public Deck, public QMainWindow
{
private:
    /**
        @brief The number of 'ACE characters in the handCroupier
    */
    int how_many_as;

protected:

    /**
        @brief The cards held by the croupier
    */
    std::vector<QString> handCroupier;

public:

    /**
        @brief Construct a new Croupier object
    */
    Croupier();

    /**
        @brief Destroy the Croupier object
    */
    ~Croupier();

    /**
        @brief Get the number of 'A' characters in the string
        @return int The number of 'A' characters in the string
     */
    int getHowManyAs() { return this->how_many_as; };

    /**
        @brief Set the number of 'A' characters in the string
        @param how_many_as The number of 'A' characters in the string
    */
    void setHowManyAs(int how_many_as) { this->how_many_as = how_many_as; };

    /**
        @brief Add the specified number of cards from the given deck to the Croupier's hand.
        @param count The number of cards to add.
        @param decks The deck to add the cards from.
    */
    void addCards(int count, Deck* decks);

    /**
        @brief Show the specified number of cards from the Croupier's hand on the UI.
        @param count The number of cards to show.
        @param ui The UI object where the cards will be shown.
    */
    void showHandDeck(int count,Ui::MainWindow *ui);

    /**
        @brief Count the total points of the cards in the Croupier's hand.
        @return The total points of the Croupier's hand.
    */
    int countPoints();

    /**
        @brief Check if the croupier hand point is less than or equal to 16. If so, add cards until it's greater than 16
        @param decks The deck to add the cards from.
        @return The number of cards added to the croupier hand
    */
    int lessOrMore(Deck* decks);

    /**
        @brief Check if the first card of the croupier's hand is an Ace.
        @return true if the first card of the croupier's hand is an Ace, false otherwise.
    */
    bool checkInsurance();

    /**
        @brief Clear the croupier's hand.
    */
    void clearHand();

    /**
        @brief Returns the number of cards in the croupier's hand
        @return number of cards in the croupier's hand
    */
    size_t howManyCardsInHand();

    /**
        @brief Check if the given needle is a substring of the given haystack.
        @tparam T The type of the characters in the strings.
        @param haystack The string to search in.
        @param needle The substring to search for.
        @return true if the needle is a substring of the haystack, false otherwise.
    */
    template<class T>
    bool IsSubstring(const std::basic_string<T>& haystack, const T* needle)
    {
        return haystack.find(needle) != std::basic_string<T>::npos;
    }
};
#endif // CROUPIER_H
