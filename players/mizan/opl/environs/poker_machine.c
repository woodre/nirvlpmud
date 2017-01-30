/*****************************************************************************
 *      File:                   poker_machine.c
 *      Function:               Reappropriated and has a 500 coin ante.
 *      Author(s):              Mizan@Nirvana
 *      Copyright:              Copyright (c) 2011 Mizan@Nirvana
 *                              All Rights Reserved.
 *      Source:                 2/2011
 *      Notes:
 *      Change History:         DONE Initial revision - 09 Mar 2011
 ****************************************************************************/

/*
 poker_machine.c - from who knows where
                   (This is single handed poker, with varying odds.
                    The game reshuffles every 4 rounds.)
*/

/* The directory where the file will be kept. */
#define PATH     "players/mizan/opl/data/"

/* The name of the file (without .c)          */
#define FILENAME "poker_machine"

/*
 Some basic defines for the odds, to change at your leisure.
 NOTE:  These MUST be integer types, not real.
*/
#define NOTHING     0   /* The player won nothing, so he gets nothing    */
#define TWOKIND     1   /* Two of a Kind, Jacks or Better                */
#define TWOPAIR     2   /* Two Pair                                      */
#define THREEKIND   3   /* Three of a Kind                               */
#define STRAIGHT    3   /* Normal Straight                               */
#define FLUSH       3   /* Normal Flush                                  */
#define FULLHOUSE   4   /* Full House (2 Kind/3 Kind)                    */
#define FOURKIND    5   /* Four of a Kind                                */
#define STRFLUSH    10  /* A Straight and a Flush Combined               */
#define ROYALFLUSH  20  /* Royal Flush                                   */

/*
 The game will reshuffle every four turns.
 (To make the game harder, just lower this number.)
*/
#define SHUFFLECNT  4   /* The number of rounds between shuffles         */

/*
 This define is for those who wish to set the time between actions.
 It is set to 60 seconds, so that if a player doesn't move within that time,
 the game will exit him out and allow for other players.
*/
#define MAX_TIME 60     /* Total time allotted to one player game        */

/* Add some easier stated defines in the game. */
#define NUM_CARDS   5
#define TRUE        1
#define FALSE       0
#define HEARTS      0
#define DIAMONDS    1
#define SPADES      2
#define CLUBS       3

/* Defines for the values of each card for indexing purposes. */
#define TWO         0
#define THREE       1
#define FOUR        2
#define FIVE        3
#define SIX         4
#define SEVEN       5
#define EIGHT       6
#define NINE        7
#define TEN         8
#define JACK        9
#define QUEEN       10
#define KING        11
#define ACE         12

/* These are to make looking into the cards easier. */
#define SUIT        0
#define CARD        1

/*
 Define the deck, cards, and shuffle integer values.
 (deck and cards will be converted into integer arrays)
*/
int deck, cards, shuffle;
object playerob;

/* Perform a simple for loop through the deck, and zero out the values. */
clean_deck() {
    int cnt;

    for (cnt = 0; cnt < 13; ++cnt) {
        deck[0][cnt] = 0;
        deck[1][cnt] = 0;
        deck[2][cnt] = 0;
        deck[3][cnt] = 0;
    }
}

/* Perform a simple for loop through the hand, and zero out the values. */
clean_cards() {
    int cnt;

    for (cnt = 0; cnt < NUM_CARDS; ++cnt) {
        cards[0][cnt] = 0;
        cards[1][cnt] = 0;
    }
}

reset(arg) {
    if (arg) return;

    deck     = allocate(4);
    deck[0]  = allocate(13);
    deck[1]  = allocate(13);
    deck[2]  = allocate(13);
    deck[3]  = allocate(13);
    clean_deck();
    cards    = allocate(2);
    cards[0] = allocate(NUM_CARDS);
    cards[1] = allocate(NUM_CARDS);
    clean_deck();
    shuffle = 1;
    playerob = 0;
}

id(str) {
    return str=="machine" || str=="poker machine";
}

short() {
    return "A poker machine";
}

long() {
    write("This is a poker machine, designed to play single handed\n"+
          "poker with someone who wants to play.  For instructions\n"+
          "on how to play, type in 'help poker'.  To play poker, type\n"+
          "in 'play poker'. This machine costs 500 coins to play.\n");
}

init() {
    add_action("help", "help");
    add_action("play", "play");
}

help(str) {
    if ((!str) || (str != "poker")) return;

    write("The game of poker is somewhat complex, but fun for those who\n"+
          "know how to play the game.  You are dealt five cards from a\n"+
          "normal deck.  A normal hand might look like:\n\n"+
          "     -------    -------    -------    -------    -------\n"+
          "     |6C   |    |5D   |    |9C   |    |KH   |    |KD   |\n"+
          "     |     |    |     |    |     |    |     |    |     |\n"+
          "     |   6C|    |   5D|    |   9C|    |   KH|    |   KD|\n"+
          "     -------    -------    -------    -------    -------\n"+
          "        1          2          3          4          5   \n\n"+
          "In this hand, you have a 6 of clubs, 5 of diamonds, 9 of clubs,\n"+
          "and the kings of hearts and diamonds.  The objective here is to\n"+
          "gather cards and make winning sets.  You are given one chance to\n"+
          "give up some of your cards for different ones.\n\n"+
          "[Press \"m\" or <RETURN> for more, other to quit]:");
    input_to("help2");
    return 1;
}

help2(str) {
    if ((str != "") && (str != "m") && (str != "M")) return 1;

    write("The winning sets are, along with their odds:\n\n"+
          "---------------------------------------------------\n"+
          "   Two of a Kind will return odds (" + TWOKIND    + "/1)"+
          "(Jacks or better)\n"+
          "        Two Pair will return odds (" + TWOPAIR    + "/1)\n"+
          " Three of a Kind will return odds (" + THREEKIND  + "/1)\n"+
          "        Straight will return odds (" + STRAIGHT   + "/1)\n"+
          "           Flush will return odds (" + FLUSH      + "/1)\n"+
          "      Full House will return odds (" + FULLHOUSE  + "/1)\n"+
          "  Four of a Kind will return odds (" + FOURKIND   + "/1)\n"+
          "  Straight Flush will return odds (" + STRFLUSH   + "/1)\n"+
          "     Royal Flush will return odds (" + ROYALFLUSH + "/1)\n"+
          "---------------------------------------------------\n\n"+
          "To discard, enter the numbers in this fashion:\n"+
          "Cards to discard [separated by spaces] -> 4 1\n"+
          "This will discard the 4th and 1st cards from your hand.\n\n");
    return 1;
}

clean_player() {
    string p;
    object ob;

    p = capitalize(playerob->query_name());
    say(p + " takes too long to play, and forefits his game.\n");
    ob = clone_object(PATH + "/" + FILENAME);
    move_object(ob, environment(playerob));
    destruct(this_object());
    return 1;
}

exit_out() {
    remove_call_out("clean_player");
    playerob = 0;
    return 1;
}

/* Return a random number for the card between 0-12. (2 -> A). */
get_number() {
    return random(13);
}

/* Return a random number for the suit between 0-3. (H, D, S, C). */
get_suit() {
    return random(4);
}

/* Print out the cards for the user. */
write_cards() {
    int cnt;
    string tmpstr, c1, c2, c3, c4, c5;

    c1 = "";
    c2 = "";
    c3 = "";
    c4 = "";
    c5 = "";
    for (cnt = 0; cnt < NUM_CARDS; ++cnt) {
        tmpstr = "";
        if      (cards[CARD][cnt]==TWO)      {
            tmpstr = "2";
        }
        else if (cards[CARD][cnt]==THREE)    {
            tmpstr = "3";
        }
        else if (cards[CARD][cnt]==FOUR)     {
            tmpstr = "4";
        }
        else if (cards[CARD][cnt]==FIVE)     {
            tmpstr = "5";
        }
        else if (cards[CARD][cnt]==SIX)      {
            tmpstr = "6";
        }
        else if (cards[CARD][cnt]==SEVEN)    {
            tmpstr = "7";
        }
        else if (cards[CARD][cnt]==EIGHT)    {
            tmpstr = "8";
        }
        else if (cards[CARD][cnt]==NINE)     {
            tmpstr = "9";
        }
        else if (cards[CARD][cnt]==TEN)      {
            tmpstr = "T";
        }
        else if (cards[CARD][cnt]==JACK)     {
            tmpstr = "J";
        }
        else if (cards[CARD][cnt]==QUEEN)    {
            tmpstr = "Q";
        }
        else if (cards[CARD][cnt]==KING)     {
            tmpstr = "K";
        }
        else if (cards[CARD][cnt]==ACE)      {
            tmpstr = "A";
        }
        else                                   {
            tmpstr = "X";
        }

        if      (cards[SUIT][cnt]==HEARTS)   {
            tmpstr = tmpstr + "H";
        }
        else if (cards[SUIT][cnt]==DIAMONDS) {
            tmpstr = tmpstr + "D";
        }
        else if (cards[SUIT][cnt]==SPADES)   {
            tmpstr = tmpstr + "S";
        }
        else if (cards[SUIT][cnt]==CLUBS)    {
            tmpstr = tmpstr + "C";
        }
        else                                   {
            tmpstr = tmpstr + "X";
        }

        if      (cnt==0)                     {
            c1 = tmpstr;
        }
        else if (cnt==1)                     {
            c2 = tmpstr;
        }
        else if (cnt==2)                     {
            c3 = tmpstr;
        }
        else if (cnt==3)                     {
            c4 = tmpstr;
        }
        else if (cnt==4)                     {
            c5 = tmpstr;
        }
    }
    write("     -------    -------    -------    -------    -------\n");
    write("     |"+c1+"   |    |"+c2+"   |    |"+c3+"   |    |"+c4+"   |    |"
          +c5+"   |\n");
    write("     |     |    |     |    |     |    |     |    |     |\n");
    write("     |   "+c1+"|    |   "+c2+"|    |   "+c3+"|    |   "+c4+
          "|    |   "+c5+"|\n");
    write("     -------    -------    -------    -------    -------\n");
}

deal() {
    int cnt, loop, number, suit;
    string card_suit;
    string numb_suit;

    for (cnt = 0; cnt < NUM_CARDS; ++cnt) {
        loop = FALSE;
        while (!loop) {
            suit   = get_suit();
            number = get_number();
            if (!deck[suit][number]) {
                deck[suit][number] = 1;
                cards[SUIT][cnt] = suit;
                cards[CARD][cnt] = number;
                loop = TRUE;
            }
        }
    }
    /* sort_cards(); */
    write_cards();
    write("        1          2          3          4          5   \n");
}

/* Perform a boolean sort on the cards in hand. */
sort_cards() {
    int tmp1, tmp2, sorted, cnt;

    do {
        sorted = TRUE;
        for (cnt = 0; cnt < 4; ++cnt) {
            if (cards[CARD][cnt] > cards[CARD][cnt+1]) {
                tmp1               = cards[SUIT][cnt];
                tmp2               = cards[CARD][cnt];
                cards[SUIT][cnt]   = cards[SUIT][cnt+1];
                cards[CARD][cnt]   = cards[CARD][cnt+1];
                cards[SUIT][cnt+1] = tmp1;
                cards[CARD][cnt+1] = tmp2;
                sorted             = FALSE;
            }
        }
    }
    while (!sorted);
}

/* Check to see how much the player won. */
payoff(num) {
    if (num==NOTHING) {
        say(capitalize(playerob->query_name()) +
            " loses 500 coins from the poker machine!\n");
    }
    else {
        write(" The machine gives you " + (500 * num) + " coins.\n");
        playerob->add_bank_balance(500 * num);
        say(capitalize(playerob->query_name()) +
            " wins " + (500 * num) + " coins from the poker machine!\n");
    }
    return 1;
}

/* See if the player won something. */
check_win() {
    int flag, ident, flush, straight, suit, cnt;

    write("\n");
    sort_cards();
    flush = TRUE;
    straight = TRUE;
    suit = cards[SUIT][0];
    for (cnt = 0; cnt < NUM_CARDS; ++cnt)
        if (cards[SUIT][cnt] != suit) flush    = FALSE;
    for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt)
        if (cards[CARD][cnt] != cards[CARD][cnt+1]-1) straight = FALSE;
    if ((flush==TRUE) && (straight==FALSE)) {
        write("FLUSH!");
        payoff(FLUSH);
    }
    else
        if ((straight==TRUE) && (flush==FALSE)) {
            write("STRAIGHT!");
            payoff(STRAIGHT);
        }
        else
            if ((!flush) && (!straight)) {
                if ((cards[CARD][0]==cards[CARD][3]) ||
                        (cards[CARD][1]==cards[CARD][4])) {
                    write("FOUR OF A KIND!");
                    payoff(FOURKIND);
                }
                else
                    if (((cards[CARD][0]==cards[CARD][1]) &&
                            (cards[CARD][2]==cards[CARD][4])) ||
                            ((cards[CARD][0]==cards[CARD][2])  &&
                             (cards[CARD][3]==cards[CARD][4]))) {
                        write("FULL HOUSE!");
                        payoff(FULLHOUSE);
                    }
                    else
                        if ((cards[CARD][0]==cards[CARD][2]) ||
                                (cards[CARD][1]==cards[CARD][3]) ||
                                (cards[CARD][2]==cards[CARD][4])) {
                            write("THREE OF A KIND!");
                            payoff(THREEKIND);
                        }
                        else {
                            ident = 1;
                            for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt)
                                if (cards[CARD][cnt]==cards[CARD][cnt+1])
                                    ident = ident + 1;
                            if (ident==2) {
                                flag = TRUE;
                                for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt) {
                                    if ((cards[CARD][cnt]==cards[CARD][cnt+1]) &&
                                            (cards[CARD][cnt] < JACK))
                                        flag = FALSE;
                                }
                                if (flag) {
                                    write("TWO OF A KIND!");
                                    payoff(TWOKIND);
                                }
                                else {
                                    write("You have nothing in your hand.  The game "+
                                          "takes your coins.\n(You must have Jacks or "+
                                          "better for a pair.)\n");
                                    payoff(NOTHING);
                                }
                            }
                            else
                                if (ident==3) {
                                    write("TWO PAIR!");
                                    payoff(TWOPAIR);
                                }
                                else {
                                    write("You have nothing in your hand.  The game "+
                                          "takes your coins.\n");
                                    payoff(NOTHING);
                                }
                        }
            }
            else {
                if ((flush==TRUE) && (straight==TRUE)) {
                    if (cards[CARD][0]==TEN) {
                        write("ROYAL FLUSH!!!");
                        payoff(ROYALFLUSH);
                    }
                    else {
                        write("STRAIGHT FLUSH!!\n");
                        payoff(STRFLUSH);
                    }
                }
            }
}

/* Check for discards, and give out new cards. */
discard_second(str) {
    int suit, number, cnt, loop, loop2;
    string arr;

    if (str=="") {
        write("\nOkay, keeping cards.\n"+
              "\nYour second set of cards are:\n\n");
        write_cards();
        check_win();
        exit_out();
        return 1;
    }
    str = str + " ";
    arr = explode(str, " ");
    loop = sizeof(arr);
    loop = loop - 1;
    while (loop >= 0) {
        if (sscanf(arr[loop], "%d", cnt) != 1) {
            write("Bad entry of discard cards.  All bets are off.\n");
            exit_out();
            return 1;
        }
        if ((cnt < 1) || (cnt > NUM_CARDS)) {
            write("Bad entry of discard cards.  All bets are off.\n");
            exit_out();
            return 1;
        }
        cnt = cnt - 1;
        loop2 = FALSE;
        while (!loop2) {
            suit   = get_suit();
            number = get_number();
            if (!deck[suit][number]) {
                deck[suit][number] = 1;
                cards[SUIT][cnt] = suit;
                cards[CARD][cnt] = number;
                loop2 = TRUE;
            }
        }
        loop = loop - 1;
    }
    /* sort_cards(); */
    write("\nYour second set of cards are:\n\n");
    write_cards();
    check_win();
    exit_out();
    return 1;
}

/* Play a game of poker. */
play(str) {
    if (this_player()->query_bank_balance() < 500) {
        write("You don't enough money in your Nirvana bank account.\n");
        write("This machine withdraws money from your account electronically.\n");
        return 1;
    }
    if (!playerob)
        playerob = this_player();
    else {
        write(capitalize(playerob->query_name()) + " is playing poker.  ");
        write("Wait until "+playerob->query_pronoun()+" is done.\n");
        return 1;
    }
    say(capitalize(playerob->query_name())+
        " plays a game of poker on the poker machine.\n");
    this_player()->add_bank_balance(-500);
    call_out("clean_player", MAX_TIME);
    playerob = this_player();
    clean_cards();
    if (SHUFFLECNT==shuffle) {
        write("The dealer reshuffles the deck.\n");
        clean_deck();
        shuffle = 1;
    }
    else {
        shuffle = shuffle + 1;
    }
    write("The machine deals you some cards:\n\n");
    deal();
    write("\n");
    write("Which ones would you like to discard? [<RETURN> for none]\n");
    write("Cards to discard [separated by spaces] -> ");
    input_to("discard_second");
    return 1;
}
