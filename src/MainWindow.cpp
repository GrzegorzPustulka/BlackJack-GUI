#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("BLACK JACK BY GRZEGORZ PUSTULKA");

    ui->standBtn->setVisible(false);
    ui->hitBtn->setVisible(false);
    ui->doubleDownBtn->setVisible(false);
    ui->insuranceBtn->setVisible(false);
    ui->exit_Btn->setVisible(false);

    hideMoneyBtn();
    ui->label_currently_money->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_playBtn_clicked()
{
    ui->label_instruction->hide();
    ui->playBtn->hide();
    ui->instrBtn->hide();
    ui->label_bet->clear();
    ui->label_points_croupier->clear();
    ui->label_points_player->clear();
    ui->label_result->clear();
    ui->label_money->setVisible(true);
    ui->exit_Btn->setVisible(false);
    ui->label_money->setText(QString("How much money\ndo you want to bet?"));
    ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));

    ui->money10Btn->setVisible(true);
    ui->money20Btn->setVisible(true);
    ui->money50Btn->setVisible(true);
    ui->money100Btn->setVisible(true);
    ui->money200Btn->setVisible(true);
    ui->money300Btn->setVisible(true);
    ui->money500Btn->setVisible(true);
    ui->money1000Btn->setVisible(true);

    ui->label_card_player1->clear();
    ui->label_card_player2->clear();
    ui->label_card_player3->clear();
    ui->label_card_player4->clear();
    ui->label_card_player5->clear();
    ui->label_card_player6->clear();
    ui->label_card_croupier1->clear();
    ui->label_card_croupier2->clear();
    ui->label_card_croupier3->clear();
    ui->label_card_croupier4->clear();
    ui->label_card_croupier5->clear();
    ui->label_card_croupier6->clear();

}

void MainWindow::on_betBtn_clicked()
{
    hideMoneyBtn();
    croupier.clearHand();
    player1.clearHand();

    ui->label_name_player->setText(QString("PLAYER"));
    ui->label_name_crupier->setText(QString("CROUPIER"));

    burn = false;
    boolNewRound = false;
    hits = 0;
    adds = 0;
    insurance = false;
    player1.setHowManyAs(0);
    croupier.setHowManyAs(0);
    player1.addCards(2 , &decks);
    croupier.addCards(2 , &decks);
    player1.showHandDeck(2, ui);
    ui->label_points_player->setText(QString::number(player1.countPoints()) + QString(" Points"));
    croupier.showHandDeck(1 , ui);


    ui->hitBtn->setVisible(true);
    ui->standBtn->setVisible(true);
    ui->doubleDownBtn->setVisible(true);
    if(croupier.checkInsurance())
        ui->insuranceBtn->setVisible(true);
    else
        ui->insuranceBtn->setVisible(false);
}

void MainWindow::on_standBtn_clicked()
{
    croupier.showHandDeck(2, ui);
    ui->label_points_croupier->setText(QString::number(croupier.countPoints()) + QString(" Points"));

    if (insurance && croupier.howManyCards() == 2 && croupier.countPoints() == 21) {
            player1.setCurrentlyMoney(player1.getCurrentlyMoney() + 2.5* player1.getMoneyOnBet());
            ui->label_result->setText(QString("INSURANCE"));
            ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
            boolNewRound = true;
    }
    else{
        adds = croupier.lessOrMore(&decks);

        if(adds > 0) {
            if (player1.howManyCardsInHand() == 2 && player1.countPoints() == 21) {
                player1.showHandDeck(2, ui);
                ui->label_points_player->setText(QString::number(player1.countPoints()) + QString(" Punktow"));
                ui->label_result->setText(QString("BLACK JACK"));
                player1.setCurrentlyMoney(player1.getCurrentlyMoney() + 2.5* player1.getMoneyOnBet());
                ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
                boolNewRound = true;
            }
            croupier.showHandDeck(2 + adds,ui);
            ui->label_points_croupier->setText(QString::number(croupier.countPoints()) + QString(" Points"));

            if (game.burn(&croupier, &player1,ui) && boolNewRound == false)
                burn = true;
        }

        if(burn == false && boolNewRound == false){
            if ((player1.howManyCardsInHand() == 2 && player1.countPoints() == 21) && (croupier.countPoints() != 21 || croupier.howManyCardsInHand() != 2)){

                player1.showHandDeck(2,ui);
                player1.setCurrentlyMoney(player1.getCurrentlyMoney() + 2.5* player1.getMoneyOnBet());
                ui->label_points_player->setText(QString::number(player1.countPoints()) + QString(" Points"));
                ui->label_result->setText(QString("BLACK JACK"));
            }
            else if((player1.howManyCardsInHand() == 2 && player1.countPoints() == 21) && (croupier.countPoints() != 21 || croupier.howManyCardsInHand() != 2)){
                player1.showHandDeck(2,ui);
                ui->label_points_player->setText(QString::number(player1.countPoints()) + QString(" Punktow"));
                ui->label_result->setText(QString("BLACK JACK"));
                player1.setCurrentlyMoney(player1.getCurrentlyMoney() + 2.5* player1.getMoneyOnBet());
                ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
            }
            else
                game.endResult(&player1, &croupier, hits, adds,ui);
        }
    }
    newRound();
}

void MainWindow::on_hitBtn_clicked(){
    hits++;
    player1.addCards(1 , &decks);
    player1.showHandDeck(2+hits,ui);

    if (game.burn(&player1,ui))
        newRound();
    else {
        ui->doubleDownBtn->setVisible(false);
        ui->insuranceBtn->setVisible(false);
    }
}

void MainWindow::on_doubleDownBtn_clicked(){

    player1.setCurrentlyMoney(player1.getCurrentlyMoney() - player1.getMoneyOnBet());
    ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
    ui->label_bet->setText((QString("In bet ")+ QString::number(2*player1.getMoneyOnBet())) + QString(" $"));

    if(player1.getCurrentlyMoney() < 0){
        this->close();
        QMessageBox::information(nullptr,"Info","You tried to cheat the croupier.\nYou didn't have that much cash.\nYou are kicked off the table.");
    }

    player1.addCards(1 , &decks);
    player1.showHandDeck(3, ui);

    if (game.burn(&player1, ui))
        boolNewRound = true;
    else{

        croupier.showHandDeck(2,ui);
        ui->label_points_croupier->setText(QString::number(croupier.countPoints()) + QString(" Points"));
        adds = croupier.lessOrMore(&decks);

        if (adds > 0) {
            croupier.showHandDeck(2 + adds,ui);
            ui->label_points_croupier->setText(QString::number(croupier.countPoints()) + QString(" Points"));

            if (game.burn(&croupier, &player1,ui)) {
                player1.setCurrentlyMoney(player1.getCurrentlyMoney() + 4 * player1.getMoneyOnBet());
                boolNewRound = true;
            }
        }
    }

    if(boolNewRound == false)
        game.endResultDoubleDown(&player1, &croupier, 1, adds,ui);

    newRound();
}

void MainWindow::on_exit_Btn_clicked(){
    this->close();
    QString information = "You finished the game with " + QString::number(player1.getCurrentlyMoney()) + "$";
    QMessageBox::information(nullptr,"Info",information);
}


void MainWindow::newRound(){
    ui->hitBtn->setVisible(false);
    ui->standBtn->setVisible(false);
    ui->doubleDownBtn->setVisible(false);
    ui->insuranceBtn->setVisible(false);
    ui->playBtn->setVisible(true);
    ui->exit_Btn->setVisible(true);
    player1.setMoneyOnBet(0);
}

void MainWindow::on_insuranceBtn_clicked(){
    player1.setCurrentlyMoney(player1.getCurrentlyMoney() - 0.5*player1.getMoneyOnBet());
    ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
    ui->label_bet->setText((QString("In bet ")+ QString::number(2*player1.getMoneyOnBet())) + QString(" $"));
    if(player1.getCurrentlyMoney() < 0){
        this->close();
        QMessageBox::information(nullptr,"Info","You tried to cheat the croupier.\nYou didn't have that much cash.\nYou are kicked off the table.");
    }
    insurance = true;
    ui->insuranceBtn->setVisible(false);
}

void MainWindow::hideMoneyBtn(){

    ui->money1000Btn->setVisible(false);
    ui->money10Btn->setVisible(false);
    ui->money20Btn->setVisible(false);
    ui->money50Btn->setVisible(false);
    ui->money100Btn->setVisible(false);
    ui->money200Btn->setVisible(false);
    ui->money300Btn->setVisible(false);
    ui->money500Btn->setVisible(false);
    ui->betBtn->setVisible(false);

    ui->label_money->hide();
    ui->label_currently_money->setText((QString("You have ")+ QString::number(player1.getCurrentlyMoney())) + QString(" $"));
}

void MainWindow::on_instrBtn_clicked()
{
    ui->label_instruction->setText(QString("                                                                                         ZASADY GRY W BLACK JACKA\n\n"
                               "Gracz Gra Przeciwko krupierowi. Wygrywa ten kto będzie bliżej 21 punktów, lub zdobędzie Black Jacka\n"
                               "czyli Asa i '10', bądź inną figurę punktowaną za 10 pkt. Gdy ktoś zdobędzie więcej niż 21 punktów,\n"
                               "wówczas przegrywa. Krupier zawsze musi dobierać karty do momentu, w którym będzie miał 17 lub więcej punktów.\n"
                               "Jeśli już zdobędzie więcej punktów, np. 18 wtedy nie może dobierać więcej kart. W przypadku remisu graczowi\n"
                               "zwraca się postawioną stawkę.\n\n"
                               "rupier zaczyna rozdawać karty odkryte od pierwszego gracza po jego lewej stronie, jedną kartę odkrytą\n"
                               "rozdaje także sobie, następnie ponownie rozdaję po jednej karcie odkrytej dla graczy, oraz jedną zakrytą\n"
                               "dla siebie\n\n"
                               "(HIT)                - gracz otrzyma kolejna karte.\n"
                               "(STAND)          - gracz nie dobiera kolejnej karty\n"
                               "(DOUBLE)        - w tym przypadku podwaja się stawke, gracz otrzyma wtedy jeszcze jedną ostatnia karte\n"
                               "(INSURANCE)  - Jesli odkryta karta krupiera jest As mozemy się ubezpieczyc na wypadek Black Jacka.\n"
                               "	            Wowczas dodatkowo stawiamy polowe swojej postawionej stawki na zaklad i jesli faktycznie krupier\n"
                               "	            bedzie miał Black Jacka to dostaniemy zwrot stawki i ubezpieczenie ktore postawilismy.\n"
                               "	            Jesli rozdajacy nie ma Black Jacka, gracz traci ubezpieczenie i rozdanie jest rozgrywane do konca"));
    ui->instrBtn->hide();
}

void MainWindow::on_money10Btn_clicked()
{
    player1.bet(10, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money20Btn_clicked()
{
    player1.bet(20, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money50Btn_clicked()
{
    player1.bet(50, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money100Btn_clicked()
{
    player1.bet(100, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money200Btn_clicked()
{
    player1.bet(200, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money300Btn_clicked()
{
    player1.bet(300, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money500Btn_clicked()
{
    player1.bet(500, ui);
    ui->betBtn->setVisible(true);
}

void MainWindow::on_money1000Btn_clicked()
{
    player1.bet(1000, ui);
    ui->betBtn->setVisible(true);
}


