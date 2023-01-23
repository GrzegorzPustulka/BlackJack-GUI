#include <player.h>

Player::Player() {
    handPlayer = {};
    how_many_as = 0;
    initMoney();
}
Player::~Player() {

}

void Player::initMoney() {
    int account = 1000;
    this->moneyOnBet = 0;
    this->startMoney = account;
    this->currentlyMoney = account;
}

void Player::addCards(int count, Deck* decks) {
    for (int i = 0; i < count; ++i){
        if(decks->howManyCards() != 0)
            handPlayer.push_back(decks->deck[i]);
       else {
            setCurrentlyMoney(getCurrentlyMoney()+ getMoneyOnBet());
            std::cout << "You finished the game with: " << getCurrentlyMoney() << " $\n";
            exit(0);
        }
    }
    decks->removeCardsFromDeck(count);
}

void Player::showHandDeck(int count, Ui::MainWindow *ui) {
    std::vector<QLabel*> labels = {ui->label_card_player1, ui->label_card_player2, ui->label_card_player3,ui->label_card_player4,ui->label_card_player5,ui->label_card_player6};

    for(int i = 0; i < count;i ++) {
            if (i == 6) {
                QMessageBox::information(nullptr,"Info","Suprise");
                exit(0);
            }
            labels[i]->setPixmap(photos[handPlayer[i]]);
        }
}

int Player::countPoints() {

    int points = 0;

    for (QString &card : handPlayer) {
        for (auto& element : deckPoint) {
            if (card == element.first)
            {
                points += element.second;
                if (IsSubstring(card.toStdString(), "As"))
                    setHowManyAs(getHowManyAs() + 1);
            }
        }
    }

    while(points > 21 && getHowManyAs() > 0){
        points -= 10;
        setHowManyAs(getHowManyAs() - 1);
    }

    setHowManyAs(0);
    return points;
}

void Player::bet(int moneyOnBet, Ui::MainWindow *ui) {
    this->setMoneyOnBet(moneyOnBet + getMoneyOnBet());
    this->setCurrentlyMoney(getCurrentlyMoney() - moneyOnBet);
    ui->label_bet->setText((QString("In bet ")+ QString::number(getMoneyOnBet())) + QString(" $"));
    if(getCurrentlyMoney() < 0){
        QMessageBox::information(nullptr,"Info","You tried to cheat the croupier.\nYou didn't have that much cash.\nYou are kicked off the table.");
        exit(0);
    }
}

void Player::clearHand() {
    handPlayer.clear();
}

void Player::gameOver(int money){
    if(money == 0){
        QMessageBox::information(nullptr,"Info","You have lost all your money.\nYou have been kicked out of the casino");
        exit(0);
    }
}

size_t Player::howManyCardsInHand(){
    size_t size = handPlayer.size();
    return size;
}

