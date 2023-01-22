#ifndef GAME_H
#define GAME_H

#include "croupier.h"
#include "player.h"

class Game: public Croupier, public Player
{
public:
    Game();
    ~Game();

    /**
    @brief Determines the winner of the game between the player and the croupier.
    @param player Pointer to the Player object representing the player.
    @param croupier Pointer to the Croupier object representing the croupier.
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function compares the points of the player and the croupier. If the player has less points,
    the croupier wins and the player loses their bet. If the player has more points, the player wins
    and their money is increased by 2 times the amount of their bet. If the points are equal, it is
    a draw and the player's money is increased by their bet. The results are displayed on the UI.
    */
    void whoWon(Player* player, Croupier* croupier, Ui::MainWindow *ui);
    /**

    @brief Check if the player has burned.
    @param player Pointer to the Player object representing the player.
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function checks if the player has more than 21 points. If so, the player loses.
    The result is displayed on the UI and the player's money is decreased by the amount of their bet.
    If the player does not have more than 21 points, the function returns false.
    */
    bool burn(Player* player,Ui::MainWindow *ui);
    /**

    @brief Check if the croupier has burned.
    @param croupier Pointer to the Croupier object representing the croupier.
    @param player Pointer to the Player object representing the player.
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function checks if the croupier has more than 21 points. If so, the player wins and the croupier loses.
    The result is displayed on the UI and the player's money is increased by 2 times the amount of their bet.
    If the croupier does not have more than 21 points, the function returns false.
    */
    bool burn(Croupier* croupier, Player* player, Ui::MainWindow *ui);
    /**

    @brief Displays the final results of the game
    @param player Pointer to the Player object representing the player.
    @param croupier Pointer to the Croupier object representing the croupier.
    @param hits Number of cards hit by the player
    @param adds Number of cards added by the croupier
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function shows the final hands of the player and the croupier on the UI,
    the number of points of each and the winner of the game.
    */
    void endResult(Player* player1, Croupier* croupier, int hits, int adds, Ui::MainWindow *ui);
    /**

    @brief Displays the final results of the game after a double down
    @param player Pointer to the Player object representing the player.
    @param croupier Pointer to the Croupier object representing the croupier.
    @param hits Number of cards hit by the player
    @param adds Number of cards added by the croupier
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function shows the final hands of the player and the croupier on the UI,
    the number of points of each and the winner of the game after a double down.
    */
    void endResultDoubleDown(Player* player1, Croupier* croupier, int hits, int adds, Ui::MainWindow *ui);
    /**

    @brief Determines the winner of the game between the player and the croupier after a double down.
    @param player Pointer to the Player object representing the player.
    @param croupier Pointer to the Croupier object representing the croupier.
    @param ui Pointer to the Ui::MainWindow object representing the UI of the game.
    The function compares the points of the player and the croupier. If the player has less points,
    the croupier wins and the player loses their double bet. If the player has more points, the player wins
    and their money is increased by 4 times the amount of their bet. If the points are equal, it is
    a draw and the player's money is increased by 2 times the amount of their bet. The results are displayed on the UI.
    */
    void whoWonDoubleDown(Player* player, Croupier* croupier, Ui::MainWindow *ui);

};

#endif // GAME_H
