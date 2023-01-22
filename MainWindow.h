#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <deck.h>
#include <player.h>
#include <croupier.h>
#include <game.h>
#include "ui_mainwindow.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_playBtn_clicked();
    void on_startBtn_clicked();
    void on_instrBtn_clicked();
    void on_standBtn_clicked();
    void on_betBtn_clicked();
    void on_hitBtn_clicked();
    void on_zakoncz_Btn_clicked();
    void on_doubleDownBtn_clicked();
    void on_insuranceBtn_clicked();

    void on_money1000Btn_clicked();
    void on_money10Btn_clicked();
    void on_money20Btn_clicked();
    void on_money50Btn_clicked();
    void on_money100Btn_clicked();
    void on_money200Btn_clicked();
    void on_money300Btn_clicked();
    void on_money500Btn_clicked();

private:
    Deck decks;
    Player player1;
    Croupier croupier;
    Game game;
    int hits;
    int adds = 0;

    bool burn = false;
    bool insurance = false;
    bool endGame = false;
    bool boolNewRound = false;
    void hideMoneyBtn();
    void newRound();
};
#endif // MAINWINDOW_H
