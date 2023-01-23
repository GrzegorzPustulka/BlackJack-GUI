#ifndef DECK_H
#define DECK_H
#include <QMainWindow>
#include <iostream>
#include <vector>
#include <map>
#include <QPixmap>
#include <algorithm>
#include <random>
#include <QMessageBox>

class Deck
{
private:

    /**
        @brief primaryDeck is a vector container of QString objects representing the primary deck of cards.
    */
    std::vector<QString> primaryDeck;

    /**
        @brief howManyDeck is an integer variable that holds the number of decks used in the game.
    */
    int howManyDeck;

public:

    /**
        @brief deck is a vector container of QString objects representing the current deck of cards.
    */
    std::vector<QString> deck;

    /**
        * @brief A map of card points
        *
        * This is a data member of the Deck class, it is a map of QString and int. It stores the point value of each card in the primaryDeck.
        * It is used to calculate the points of a player's hand and it is initialized in the constructor.
        * The key of the map is the card name in the primaryDeck, and the value is the point value of the card.
    */
    std::map<QString, int> deckPoint;

    /**
        * @brief A map of card images
        *
        * This is a data member of the Deck class, it is a map of QString and QPixmap. It stores the image of each card in the primaryDeck.
        * It is used to show the cards on the screen. The key of the map is the card name in the primaryDeck, and the value is the image of the card.
        * The images are loaded in the constructor using the QPixmap class.
    */
    std::map<QString, QPixmap> photos;

    /**
        * @brief Constructor for Deck class
        *
        * This function is the constructor for the Deck class. It initializes several data members of the class: primaryDeck, deckPoint, photos, howManyDeck.
        * primaryDeck is initialized with a set of strings representing the standard 52 cards in a deck.
        * deckPoint is initialized with the corresponding point value for each card in the primaryDeck.
        * photos is a map which stores the QPixmap of each card in the primaryDeck using the key as the card name and the value as the QPixmap.
        * howManyDeck is the number of decks that are used to play the game. It is randomly generated between 1 and 8.
        * createDeck() function is called to create a new deck of cards
        * shuffle() function is called to shuffle the cards in the deck.
        *
        * @param None
        * @return None
    */
    Deck();

    /**
        * @brief Destructor for Deck class
        *
        * This function is the destructor for the Deck class. It is responsible for freeing up any dynamically allocated memory or resources that the object has acquired during its lifetime.
        *
        * @param None
        * @return None
    */
    ~Deck();

    /**
        * @brief Create a new deck of cards
        *
        * This function creates a new deck of cards by copying the primaryDeck (52 cards) into the deck vector, howManyDeck times.
        *
        * @param None
        * @return None
    */
    void createDeck();

    /**
        * @brief Remove cards from the deck
        *
        * This function removes a specified number of cards from the top of the deck vector. If the deck runs out of cards, the game ends.
        *
        * @param count The number of cards to remove from the deck
        * @return None
    */
    void removeCardsFromDeck(int count);

    /**
        * @brief Shuffle the deck of cards
        *
        * This function shuffles the elements of the deck vector using the C++ algorithm std::shuffle and a random number generator.
        *
        * @param None
        * @return None
    */
    void shuffle();

    /**
        * @brief Get the number of cards in the deck
        *
        * This function returns the number of cards in the deck by getting the size of the deck vector.
        *
        * @param None
        * @return An integer representing the number of cards in the deck
    */
    size_t howManyCards();

};

#endif // DECK_H
