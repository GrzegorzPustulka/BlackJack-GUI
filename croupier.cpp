#include "croupier.h"

Croupier::Croupier() {
    this->handCroupier = {};
    this-> how_many_as = 0;
}

Croupier::~Croupier() {

}

void Croupier::addCards(int count, Deck* decks) {
    for (int i = 0; i < count; ++i){
        if(decks->howManyCards() != 0)
            handCroupier.push_back(decks->deck[i]);
        else
        {
            QMessageBox::information(nullptr,"Info","the cards in the deck are over");
            exit(0);
        }
    }
    decks->removeCardsFromDeck(count);
}

void Croupier::showHandDeck(int count, Ui::MainWindow *ui) {
    std::vector<QLabel*> labels = {ui->label_card_croupier1, ui->label_card_croupier2, ui->label_card_croupier3,ui->label_card_croupier4,ui->label_card_croupier5,ui->label_card_croupier6};

    for(int i = 0; i < count;i ++) {
        labels[i]->setPixmap(photos[handCroupier[i]]);
    }
}

int Croupier::countPoints() {
    int points = 0;

    for (QString& card : handCroupier) {
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

int Croupier::lessOrMore(Deck* decks) {
    int nowPointCroupier = countPoints();
    int adds = 0;

    while (nowPointCroupier <= 16){
        addCards(1, decks);
        nowPointCroupier = countPoints();
        adds++;
    }

    return adds;
}

bool Croupier::checkInsurance() {
    QString cardOne = handCroupier[0];

    if (cardOne.toStdString().substr(0, 2) == "As")
        return true;
    else
        return false;
}

size_t Croupier::howManyCardsInHand(){
    size_t size = handCroupier.size();
    return size;
}

void Croupier::clearHand() {
    handCroupier.clear();
}
