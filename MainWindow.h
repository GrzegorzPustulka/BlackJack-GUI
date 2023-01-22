#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <deck.h>
#include <player.h>
#include <croupier.h>
#include <game.h>
#include <Polimorfizm.cpp>
#include "ui_mainwindow.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
        * @brief Constructor of the MainWindow class
        *
        * @param parent A pointer to the parent widget
    */
    MainWindow(QWidget *parent = nullptr);

    /**
        * @brief Destructor of the MainWindow class
        *
    */
    ~MainWindow();

    /**
        * @brief The ui pointer
    */
    Ui::MainWindow *ui;

private slots:

    /**
        * @brief This method is used to handle the click event of the play button.
        *
        * When the play button is clicked, the method hides certain UI elements, clears
        * certain labels, sets certain labels to be visible, and clears certain card labels.
        *
        * @param none
        * @return void
    */
    void on_playBtn_clicked();

    /**
        * @brief Handles the event when the "Instruction" button is clicked.
        *
        * This function is called when the "Instruction" button is clicked in the GUI.
        * It sets the text of the "label_instruction" object to a string containing the rules of the game.
        * It also hides the "Instruction" button.
        *
        * @param ui Pointer to the user interface object.
    */
    void on_instrBtn_clicked();

    /**
        * @brief This method handles the click event of the bet button.
        *
        * When the bet button is clicked, this method hide certain UI elements, clear croupier and player's hand, set certain labels to be visible,
        * set certain variables to default values, add two cards for player and croupier, count points for player and croupier and make certain buttons visible.
        *
        * @param none
        * @return void
    */
    void on_betBtn_clicked();

    /**
        * @brief This method handles the click event of the exit button.
        *
        * When the exit button is clicked, this method closes the current window, and show a message box with the information
        * about the amount of money that player finished the game with.
        *
        * @param none
        * @return void
    */
    void on_exit_Btn_clicked();

    /**
        * @brief This method handles the click event of the stand button.
        *
        * When the stand button is clicked, this method shows the croupier's hidden cards, show the points of croupier, check whether the player has insurance and croupier has blackjack
        * check for burn, blackjack and endresult of the game, if the game is finished it calls newRound() method.
        *
        * @param none
        * @return void
    */
    void on_standBtn_clicked();

    /**
        * @brief This method handles the click event of the hit button.
        *
        * When the hit button is clicked, this method increments the hit variable, adds one card to the player's hand, shows the player's hand,
        * checks for burn, if the player has burn it calls newRound() method, if the player didn't burn it makes doubleDownBtn and insuranceBtn invisible.
        *
        * @param none
        * @return void
    */
    void on_hitBtn_clicked();

    /**
        * @brief This method handles the click event of the doubleDown button.
        *
        * When the doubleDown button is clicked, this method doubles the player's bet, check if the player has enough money, if not it shows a message box,
        * adds a card to the player's hand, shows the player's hand, checks for burn, shows the croupier's cards and count the points, check for burn,
        * if no burn calls the endResultDoubleDown method and calls newRound() method.
        *
        * @param none
        * @return void
    */
    void on_doubleDownBtn_clicked();

    /**
        * @brief Handles the event when the "Insurance" button is clicked.
        *
        * This function is called when the "Insurance" button is clicked in the GUI.
        * It subtracts half of the player's current bet from the player's total money and updates the "label_currently_money" object with this new value.
        * It also updates the "label_bet" object with the current bet x2.
        * If the player's total money becomes negative, the function closes the game and displays a message box with the appropriate message.
        * It also sets the insurance flag to true and hides the "Insurance" button.
        *
        * @param ui Pointer to the user interface object.
    */
    void on_insuranceBtn_clicked();

    /**
        * @brief Handles the event when the "10" money button is clicked.
        *
        * This function is called when the "10" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 10 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money10Btn_clicked();

    /**
        * @brief Handles the event when the "20" money button is clicked.
        *
        * This function is called when the "20" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 20 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money20Btn_clicked();

    /**
        * @brief Handles the event when the "50" money button is clicked.
        *
        * This function is called when the "50" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 50 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money50Btn_clicked();

    /**
        * @brief Handles the event when the "100" money button is clicked.
        *
        * This function is called when the "100" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 100 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money100Btn_clicked();

    /**
        * @brief Handles the event when the "200" money button is clicked.
        *
        * This function is called when the "200" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 200 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money200Btn_clicked();

    /**
        * @brief Handles the event when the "300" money button is clicked.
        *
        * This function is called when the "300" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 300 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money300Btn_clicked();

    /**
        * @brief Handles the event when the "500" money button is clicked.
        *
        * This function is called when the "500" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 500 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money500Btn_clicked();

    /**
        * @brief Handles the event when the "1000" money button is clicked.
        *
        * This function is called when the "1000" money button is clicked in the GUI.
        * It calls the `bet()` function of the `player1` object, passing in a value of 1000 and the `ui` object.
        * It also makes the "bet" button visible in the GUI.
        *
        * @param ui Pointer to the user interface object
    */
    void on_money1000Btn_clicked();
private:

    /**
        * @brief A deck of cards
    */
    Deck decks;

    /**
        * @brief A player object
    */
    Player player1;

    /**
        * @brief A croupier object
    */
    Croupier croupier;

    /**
        * @brief A game object
    */
    Game game;

    /**
     * @brief The number of hits
    */
    int hits;

    /**
     * @brief The number of added card
    */
    int adds;

    /**
        *@brief The burn status
    */
    bool burn = false;

    /**
        * @brief The insurance status
    */
    bool insurance = false;

    /**
        * @brief The end game status
    */
    bool endGame = false;

    /**
        * @brief The new round status
    */
    bool boolNewRound = false;

    /**
        * @brief Hide buttons and labels related to money
    */
    void hideMoneyBtn();

    /**
        * @brief Start a new round
    */
    void newRound();
};
#endif // MAINWINDOW_H
