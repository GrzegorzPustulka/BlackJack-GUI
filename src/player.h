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

    /**
        * @brief The cards held by the player
    */
    std::vector<QString> handPlayer;

    /**
        * @brief The start amount of money
    */
    int startMoney;

    /**
        * @brief The current amount of money
    */
    int currentlyMoney;

    /**
        * @brief The amount of money on bet
    */
    int moneyOnBet;

    /**
        * @brief The number of 'A' characters in the handPlayer
    */
    int how_many_as;

    /**
        * @brief Initializes the money for a player object
        *
        * This function initializes the player's account to 1000 and writes this value to a binary file named "fileBin.bin" using an ofstream object. Then it sets the account variable to 0 and reads the value from the binary file using an ifstream object and assigns it to the player's starting and current money values (this->startMoney and this->currentlyMoney). It also sets the player's money on bet to 0.
        *
        * @param None
        * @return None
    */
    void initMoney();

public:

    /**
        * @brief Construct a new Player object
    */
    Player();

    /**
        * @brief Destroy the Player object
    */
    ~Player();

    /**
        * @brief Get the start amount of money
        *
        * @return int The start amount of money
    */
    int getStartMoney() { return this->startMoney; };

    /**
        * @brief Set the start amount of money
        *
        * @param startMoney The start amount of money
    */
    void setStartMoney(int startMoney) { this->startMoney=startMoney; };

    /**
        * @brief Get the current amount of money
        *
        * @return int The current amount of money
    */
    int getCurrentlyMoney() { return this->currentlyMoney; };

    /**
        * @brief Set the current amount of money
        *
        * @param currentlyMoney The current amount of money
    */
    void setCurrentlyMoney(int currentlyMoney) { this->currentlyMoney = currentlyMoney; };

    /**
        * @brief Get the amount of money on bet
        *
        * @return int The amount of money on bet
    */
    int getMoneyOnBet() { return this->moneyOnBet; };

    /**
        * @brief Set the amount of money on bet
        *
        * @param moneyOnBet The amount of money on bet
    */
    void setMoneyOnBet(int moneyOnBet) { this->moneyOnBet = moneyOnBet; };

    /**
        * @brief Get the number of 'ACE' characters in the handCroupier
        *
        * @return int The number of 'ACE' characters in the handCroupier
    */
    int getHowManyAs() { return this->how_many_as; };

    /**
        * @brief Set the number of 'ACE' characters in the handCroupier
        *
        * @param how_many_as The number of 'ACE' characters in the handCroupier
    */
    void setHowManyAs(int how_many_as) { this->how_many_as = how_many_as; };

    /**
        * @brief Add cards to player's hand
        *
        * This function adds a specified number of cards from a deck to the player's hand. If the deck runs out of cards, the player's current money is updated with the money on bet and the game ends.
        *
        * @param count The number of cards to add to the player's hand
        * @param decks Pointer to the Deck object from which the cards will be drawn
        * @return None
    */
    void addCards(int count, Deck* decks);

    /**
        * @brief Show player's hand on the screen
        *
        * This function displays a specified number of cards from the player's hand on the screen by updating the pixmap of a set of QLabel objects.
        *
        * @param count The number of cards to display from the player's hand
        * @param ui Pointer to the MainWindow object which contains the QLabel objects to update
        * @return None
    */
    void showHandDeck(int count, Ui::MainWindow *ui);

    /**
        * @brief Counts the total points of the player's hand
        *
        * This function iterates through the cards in the player's hand, and adds the corresponding point value to a total points variable.
        * If a card is an Ace, it also increments a counter of the number of Aces in the hand.
        * Finally, it checks if the total points is greater than 21, and if so, it subtracts 10 points for each Ace in the hand until the total points is less than or equal to 21.
        *
        * @param None
        * @return An integer representing the total points of the player's hand
    */
    int countPoints();

    /**
        * @brief Place a bet
        *
        * This function allows the player to place a bet by adding a specified amount of money to the current money on bet.
        * It also updates the current amount of money the player has and updates the bet label in the MainWindow UI
        * if the player has less money than the bet, it shows an error message and the game will be closed.
        *
        * @param moneyOnBet The amount of money the player wants to bet
        * @param ui Pointer to the MainWindow object which contains the label to update
        * @return None
    */
    void bet(int money, Ui::MainWindow *ui);

    /**
        * @brief Clear player's hand
        *
        * This function clears the player's current hand by removing all elements from the handPlayer vector.
        *
        * @param None
        * @return None
    */
    void clearHand();

    /**
        * @brief End the game
        *
        * This function checks if the player has run out of money and shows a message box with information about the end of the game and close the game.
        *
        * @param money The current amount of money the player has
        * @return None
    */
    void gameOver(int money);

    /**
        * @brief Get the number of cards in player's hand
        *
        * This function returns the number of cards in the player's hand by getting the size of the handPlayer vector.
        *
        * @param None
        * @return An integer representing the number of cards in the player's hand
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

#endif // PLAYER_H
