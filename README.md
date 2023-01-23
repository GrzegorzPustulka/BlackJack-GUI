# BlackJack-GUI

It is an implementation of the popular BlackJack casino game made in c++ using libary QT to make the graphical user interface.

## Rules

The player decides what choice he wants to make. The croupier must stick to the set rules, when he has less than 17 points, he must draw additional cards.
Each card is counted by its value, but Jack, Queen, King is 10 points. An ace is counted as 1 or 11, whichever is better for the player or the croupier

<b>Stand</b>: Take no more cards.

<b>Hit</b>: Take another card.

<b>Double down</b>: Double the wager, take exactly one more card, and then stand.

<b>Insurance</b>: It's a side bet, which is offered to the players when the dealer’s up card is an ace. Takes an additional half of the chips plac                                  It insures the player against the dealer having a ‘blackjack’ and gives them a chance to break even on the hand, if the dealer’s                                cards total 21.

BlackJack is paid out as 250% of the bet placed. BlackJack is only when we have 2 cards (Ace and "10") and the croupier does not have BlackJack.\n
If we are closer to 21 points than the dealer and nobody has gone over 21 points, we get 200% of our bet.

if the dealer is closer to 21 points than you and no one has passed 21 points, we lose the placed bet.

If the dealer had BlackJack and we placed an additional insurance bet, we recover the placed bet.

If we exceed 21 points we lose the placed bet.

If the dealer exceeds 21 points, we get 200% of our bet.

If there is a tie we get 100% of the bet placed.


## Screens shots

<img
  src="/pictures/menu.png"
  alt="Menu"
  title="Black Jack Menu"
  width="500"
  height="375"
  style="display: inline-block; margin: 0 auto">

<img
  src="/pictures/bet.png"
  alt="bet"
  title="Black Jack bet"
  width="500"
  height="375"
  style="display: inline-block; margin: 0 auto">
  
<img
  src="/pictures/result.png"
  alt="bet"
  title="Black Jack end result"
  width="500"
  height="375"
  style="display: inline-block; margin: 0 auto">
  
<img
  src="/pictures/choose.png"
  alt="bet"
  title="Black Jack choose"
  width="500"
  height="375"
  style="display: inline-block; margin: 0 auto">
