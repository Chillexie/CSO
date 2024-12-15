//package Blackjack;
/* Lexie Chen
 * dkt4kr
 * HW4 - Blackjack
 */

/*
 * Define a blackjack player by inheriting from the superclass BlackjackPlayer
 *   and implementing the 3 abstract methods.
 */
public class MyBlackjackPlayer extends BlackjackPlayer{

	@Override
	/* if the player loses one round, they should double their
	 * bet for the next round for a higher chance of winning
	 * the lost back and make profit
	 */
	public int getBet() {
		int bet = 10;
		if (getChips() >= 0){
				if (getChips() < 1000- bet){
					bet *= 2;
				}
		}
		return bet;

	}

	@Override
	public Move getMove() {
		/* stand on 17 or above */
		if (this.handScore() >= 17) {
			return Move.STAY;
		}
		if (getChips() <= 0) {
			return Move.STAY;
		}
		if (this.handScore() == 12) {
			return Move.HIT;
		}
		if (this.handScore() == 15) {
			return Move.DOUBLE;
		}
		return null;
	}

	@Override
	public void handOver(Card[] dealerHand) {
	}
}

		/*
		 * If you care about looking at the dealer's hand once
		 * the hand is over, then you can do it here. This method
		 * is called automatically after every hand and a copy of the dealer's
		 * final hand is given to you to process. The dealer's hand will be
		 * found in the array of Cards that you pass when the method returns.
		 */

