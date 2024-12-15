//package Blackjack;
/* Lexie Chen
 * dkt4kr
 * HW4 - Blackjack
 */


/**
 * A stack of more than one deck of cards used in a casino game
 *
 */
public class DeckShoe {

    //An array of decks of cards that comprise this multi-deck.
    private Deck[] decks;

    // declaring the variable that represents the total # of cards in the decks
    int totalCards;


    //Constructor: instantiates the number of decks specified and
    //adds them to the list of decks
    public DeckShoe(int numDecks) {
        decks = new Deck[numDecks];
        for (int i = 0; i < numDecks; i++){
            decks[i] = new Deck();
        }
        totalCards = numDecks * 52;
    }
    //Deals the top card from the stack of decks and returns that Card.
    //You can implement this several ways, as long as it correctly
    //deals a card from one of the decks.
    //Important: if you've dealt the last card in all the decks, you'll want
    //to reshuffle all the decks and start over again
    public Card dealTopCard() {
        for (Deck d : decks) {
            if (d.cardsLeft() <= 0) {
                d.shuffle();
            } else {
                return d.dealTopCard();
            }
        }
        return decks[0].dealTopCard();
    }



    //Reshuffles all of decks
    protected void restoreDecks(){
        for (Deck d: decks){
            d.shuffle();
            }
    }


    //returns the number of cards left to be dealt in the entire stack of cards.
    public int cardsLeft() {
        int num = 0;
        for (Deck d : decks) {
            num += d.cardsLeft();
        }
        return num;
    }

}
