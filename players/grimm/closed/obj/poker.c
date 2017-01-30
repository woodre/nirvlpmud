/*
// Poker Machine -- Play Poker!
// By : Matt D. Robinson, Copyright 1991 (Regret/Yakker)
// SCCS Directives: %W% %G%
//
// Objective:  Create a machine for a pub or bar that allows you to
//             play poker.  This is single handed poker, with varying
//             odds.  The game reshuffles every 4 rounds.
//
// Bug Reports, Problems, or Questions?  Email me at:
// yakker@ucrmath.ucr.edu, or ..!ucsd!ucrmath!yakker
//
//      Version: 1.6
// Developed at: Cornucopia MUD, soon to be open at an Internet site near you.
//    Bug Fixes: Fixed straight problem
//               Corrected problem between full house and three of a kind
//               Readjusted playerob = 0 in three necessary places
//               Added information for jacks or better
//               Put together a payoff() function.
*/

/*---------------------------------------------------------------------------*/
/* BEGIN Modifiable Defines                                                  */
/*---------------------------------------------------------------------------*/
/*
// These two defines are for where the file will be kept.  They MUST be
// made to where you would like to keep the file in your system.  Please
// change them to whatever they need to be.
//
// NOTE:  Do not put on a "/" at the end of the PATH.  It will be done
//        automatically.
*/
#define PATH  "/players/grimm/closed/obj" /* The directory where the file will be kept. */
#define FILENAME "poker"       /* The name of the file (without .c)          */

/*
// Some basic defines for the odds, to change at your leisure.
// NOTE:  These MUST be integer types, not real.
*/
#define NOTHING     0       /* The player won nothing, so he gets nothing    */
#define TWOKIND     1       /* Two of a Kind, Jacks or Better                */
#define TWOPAIR     2       /* Two Pair                                      */
#define THREEKIND   3       /* Three of a Kind                               */
#define STRAIGHT    3       /* Normal Straight                               */
#define FLUSH       3       /* Normal Flush                                  */
#define FULLHOUSE   4       /* Full House (2 Kind/3 Kind)                    */
#define FOURKIND    5       /* Four of a Kind                                */
#define STRFLUSH    10      /* A Straight and a Flush Combined               */
#define ROYALFLUSH  20      /* Royal Flush                                   */

/*
// This define can be changed for those who want to make the deck more
// fluid.  The game will reshuffle every four turns, so that the deck
// is pretty clean and the person who likes to count cards has a chance.
// To make the game harder, just lower this number.
*/
#define SHUFFLECNT  4       /* The number of rounds between shuffles         */

/*
// This define is for those who wish to set the time between moves.  Here I
// set it to 60 seconds, so that if a player doesn't move within that time,
// the game will exit him out and allow for other players.
*/
#define MAX_TIME 60         /* Total time allotted to one player game        */


/*---------------------------------------------------------------------------*/
/* END Modifiable Defines                                                    */
/*---------------------------------------------------------------------------*/

/*
// Add some easier stated defines in the game.
*/
#define NUM_CARDS   5
#define TRUE        1
#define FALSE       0
#define HEARTS      0
#define DIAMONDS    1
#define SPADES      2
#define CLUBS       3

/*
// Defines for the values of each card for indexing purposes.
*/
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

/*
// These are to make looking into the cards easier.
*/
#define SUIT        0
#define CARD        1

/*
// Define the deck, cards, and shuffle integer values (deck and cards
// will be converted into integer arrays).
*/
int deck, cards, shuffle;
object playerob;

/*
// clean_deck() -- Reset the values in the deck.
*/
clean_deck()
{
    int cnt;

    /*
    // Perform a simple for loop through the deck, and zero out the values.
    */
    for (cnt = 0; cnt < 13; ++cnt)
    {
        deck[0][cnt] = 0; deck[1][cnt] = 0;
        deck[2][cnt] = 0; deck[3][cnt] = 0;
    }
}

/*

// clean_cards() -- Clean up the hand given out to the user.
*/
clean_cards()
{
    int cnt;

    /*
    // Perform a simple for loop through the hand, and zero out the values.
    */
    for (cnt = 0; cnt < NUM_CARDS; ++cnt)
    {
        cards[0][cnt] = 0; cards[1][cnt] = 0;
    }
}

/*
// reset(arg) -- When the object is reset, set up some values.
*/
reset(arg)
{
    /*
    // If this is not the first time being reset, just return.
    */
    if (arg) return;

    /*
    // Allocate space for the deck.
    */
    deck     = allocate(4);
    deck[0]  = allocate(13);
    deck[1]  = allocate(13);
    deck[2]  = allocate(13);
    deck[3]  = allocate(13);
    clean_deck();

    /*
    // Initialize the values for the cards.
    */
    cards    = allocate(2);
    cards[0] = allocate(NUM_CARDS);
    cards[1] = allocate(NUM_CARDS);
    clean_deck();

    /*
    // Set the initial shuffle value.
    */
    shuffle = 1;
    playerob = 0;
}

/*
// id(str) -- Set the id (name) for the machine.
*/
id(str)
{
    /*
    // Return the ID for the machine.
    */
    return str == "machine" || str == "poker machine" || str == "pokermachine";
}

/*
// short() -- Set the short description on the item.

*/
short()
{
    /*
    // Return the short() to the user (for things like "look").
    */
    return "A poker machine";
}

/*
// long() -- Set the long description on the item.
*/
long()
{
    /*
    // Write out a long description on the machine.  Inform them on
    // the play command, and the help command.
    */
    write("This is a poker machine, designed to play single handed\n");
    write("poker with someone who wants to play.  For instructions\n");
    write("on how to play, type in 'help poker'.  To play poker, type\n");
    write("in 'play poker'.\n");
}

/*
// init() -- Allow some initial actions for the game.
*/
init()
{
    /*
    // Make "play" and "help" valid actions in the game.
    */
    add_action("help", "help");
    add_action("play", "play");
}

/*
// help(str) -- Show some help information to a player.
*/
help(str)
{
    /*
    // If they just type in "help", or not "help poker", return.
    */
    if ((!str) || (str != "poker"))
    {
        return 0;
    }

    /*
    // Write out some basic information.
    */
    write("The game of poker is somewhat complex, but fun for those who\n");
    write("know how to play the game.  You are dealt five cards from a\n");
    write("normal deck, all of which will be different.  A normal hand\n");
    write("might look like:\n\n");
    write("     -------    -------    -------    -------    -------\n");
    write("     |6C   |    |5D   |    |9C   |    |KH   |    |KD   |\n");
    write("     |     |    |     |    |     |    |     |    |     |\n");
    write("     |   6C|    |   5D|    |   9C|    |   KH|    |   KD|\n");
    write("     -------    -------    -------    -------    -------\n");
    write("        1          2          3          4          5   \n");
    write("\n");

    write("In this hand, you have a 6 of clubs, 5 of diamonds, 9 of clubs,\n");
    write("and a king of hearts and diamonds.  The objective here is to\n");
    write("gather cards and make winning sets.  You are given one chance to\n");
    write("give up your cards for different ones, and on the second turn,\n");
    write("those will make up your final hand.\n");
    write("\n[Press \"m\" or <RETURN> for more, other to quit]:");

    /*
    // Continue with more help in another function.  Use input_to() to
    // allow you to continue.
    */
    input_to("help2");
    return 1;
}

/*
// help2(str) -- The second set of help information.
*/
help2(str)
{
    /*
    // Make sure they want more information.
    */
    if ((str != "") && (str != "m") && (str != "M")) return 1;

    /*
    // Write out some more basic information.
    */
    write("The winning sets are, along with their odds:\n\n");
    write("---------------------------------------------------\n");
    write("   Two of a Kind will return odds (" + TWOKIND    + "/1)");
    write("(Jacks or better)\n");
    write("        Two Pair will return odds (" + TWOPAIR    + "/1)\n");
    write(" Three of a Kind will return odds (" + THREEKIND  + "/1)\n");
    write("        Straight will return odds (" + STRAIGHT   + "/1)\n");
    write("           Flush will return odds (" + FLUSH      + "/1)\n");
    write("      Full House will return odds (" + FULLHOUSE  + "/1)\n");
    write("  Four of a Kind will return odds (" + FOURKIND   + "/1)\n");
    write("  Straight Flush will return odds (" + STRFLUSH   + "/1)\n");
    write("     Royal Flush will return odds (" + ROYALFLUSH + "/1)\n");
    write("---------------------------------------------------\n");
    write("\nTo discard, enter the numbers in this fashion:\n");
    write("Cards to discard [separated by spaces] -> 4 1\n");
    write("This will discard the fourth and first card from your hand.\n\n");
    write("Brought to you by Yakker/Regret, (C)1991 all rights reserved.\n");
    return 1;
}

clean_player()
{
    string p;
    object ob;

    p = capitalize(playerob->query_name());
    say(p + " takes too long to play, and forefits his game.\n");
    ob = clone_object(PATH + "/" + FILENAME);
    move_object(ob, environment(playerob));
    destruct(this_object());
    return 1;
}

exit_out()
{

    remove_call_out("clean_player");
    playerob = 0; return 1;
}

/*
// get_number() -- Return a random number for the card. (2 -> A).
*/
get_number()
{
    /*
    // Return a random value between 0 to 12.
    */
    return random(13);
}

/*
// get_suit() -- Return a random number for the suit (H, D, S, C).
*/
get_suit()
{
    /*
    // Return a random value between 0 and 2.
    */
    return random(4);
}

/*
// write_cards() -- Print out the cards for the user.
*/
write_cards()
{
    int cnt;
    string tmpstr, c1, c2, c3, c4, c5;

    /*
    // Initialize the card strings.
    */
    c1 = ""; c2 = ""; c3 = ""; c4 = ""; c5 = "";

    /*
    // Here, assign all of the string values for the cards.
    // It's important to note that I don't have a switch statement
    // yet, so when one comes out, please adapt to that policy.
    */
    for (cnt = 0; cnt < NUM_CARDS; ++cnt)
    {
        tmpstr = "";
        /*
        // Perform if checks for the card value.
        */
        if      (cards[CARD][cnt] == TWO)      { tmpstr = "2";          }
        else if (cards[CARD][cnt] == THREE)    { tmpstr = "3";          }
        else if (cards[CARD][cnt] == FOUR)     { tmpstr = "4";          }
        else if (cards[CARD][cnt] == FIVE)     { tmpstr = "5";          }
        else if (cards[CARD][cnt] == SIX)      { tmpstr = "6";          }
        else if (cards[CARD][cnt] == SEVEN)    { tmpstr = "7";          }
        else if (cards[CARD][cnt] == EIGHT)    { tmpstr = "8";          }
        else if (cards[CARD][cnt] == NINE)     { tmpstr = "9";          }
        else if (cards[CARD][cnt] == TEN)      { tmpstr = "T";          }
        else if (cards[CARD][cnt] == JACK)     { tmpstr = "J";          }
        else if (cards[CARD][cnt] == QUEEN)    { tmpstr = "Q";          }
        else if (cards[CARD][cnt] == KING)     { tmpstr = "K";          }
        else if (cards[CARD][cnt] == ACE)      { tmpstr = "A";          }

       else                                   { tmpstr = "X";          }

        /*
        // Perform if checks for the suit value.
        */
        if      (cards[SUIT][cnt] == HEARTS)   { tmpstr = tmpstr + "H"; }
        else if (cards[SUIT][cnt] == DIAMONDS) { tmpstr = tmpstr + "D"; }
        else if (cards[SUIT][cnt] == SPADES)   { tmpstr = tmpstr + "S"; }
        else if (cards[SUIT][cnt] == CLUBS)    { tmpstr = tmpstr + "C"; }
        else                                   { tmpstr = tmpstr + "X"; }

        /*
        // Now, assign the value to the card we are currently working on.
        */
        if      (cnt == 0)                     { c1 = tmpstr;           }
        else if (cnt == 1)                     { c2 = tmpstr;           }
        else if (cnt == 2)                     { c3 = tmpstr;           }
        else if (cnt == 3)                     { c4 = tmpstr;           }
        else if (cnt == 4)                     { c5 = tmpstr;           }
    }
    /*
    // Now write out the cards for the player.
    */
    write("     -------    -------    -------    -------    -------\n");
    write("     |"+c1+"   |    |"+c2+"   |    |"+c3+"   |    |"+c4+"   |    |"
                    +c5+"   |\n");
    write("     |     |    |     |    |     |    |     |    |     |\n");
    write("     |   "+c1+"|    |   "+c2+"|    |   "+c3+"|    |   "+c4+
                    "|    |   "+c5+"|\n");
    write("     -------    -------    -------    -------    -------\n");
}

/*
// deal() -- Deal the initial cards to the user.
*/
deal()
{
    int cnt, loop, number, suit;
    string card_suit;
    string numb_suit;

    /*
    // In this for loop, assign a card to a user only if the card
    // has not already been given out.  Once all five cards are
    // given out, print them out.
    */
    for (cnt = 0; cnt < NUM_CARDS; ++cnt)
    {
        loop = FALSE;
        while (!loop)
        {
            /*
            // Get random values from the get_suit() and get_number()
            // functions, and check to see if that card is taken.
            */
            suit   = get_suit();
            number = get_number();
            if (!deck[suit][number])
            {
                /*
                // Assign that card, and break from the loop.
                */
                deck[suit][number] = 1;

                cards[SUIT][cnt] = suit;
                cards[CARD][cnt] = number;
                loop = TRUE;
            }
        }    
    }    

    /*
    // Sort the cards, write out the cards, and give numbers to
    // each card. (For discard purposes.)
    */
    /* sort_cards(); */
    write_cards();
    write("        1          2          3          4          5   \n");
}

/*
// sort_cards() -- Perform a boolean sort on the cards in hand.
*/
sort_cards()
{
    int tmp1, tmp2, sorted, cnt;

    /*
    // This is a simple bubble sort.  For more information on
    // how to do this, look it up in your nearest Pascal/C
    // beginner's book (I wanted to perform a quick sort, but
    // it would be worthless to write it out simply to perform
    // this.
    */
    do
    { 
        sorted = TRUE;
        for (cnt = 0; cnt < 4; ++cnt)
        {
            if (cards[CARD][cnt] > cards[CARD][cnt+1])
            {
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

/*
// payoff(num) -- Check to see how much the player won.
*/
payoff(num)
{
    /*
    // Rather than commenting all of this, I'll just say that the odds
    // are used as a multiplier on their coins.
    */
    if (num == NOTHING)
    {
        say(capitalize(playerob->query_name()) +
                " loses 10 coins from the poker machine!\n");

    }
    else
    {   
        write(" The machine gives you " + (10 * num) + " coins.\n");
        playerob->add_money(10 * num);
        say(capitalize(playerob->query_name()) +
                " wins " + (10 * num) + " coins from the poker machine!\n");
    }
    return 1;
}

/*
// check_win() -- See if the player won something.
*/
check_win()
{
    int flag, ident, flush, straight, suit, cnt;

    write("\n");
    /*
    // NOTE:  I'm sure this could be done better, so if you see some
    //        way to improve it, please do. ;)  But this method seems
    //        to work well on its own.
    */

    /*
    // Sort the cards.
    */
    sort_cards();

    /*
    // First, rule out the flush, if possible.  It seems to save time
    // in the long run.  Also rule out the straight.
    */
    flush = TRUE; straight = TRUE; suit = cards[SUIT][0];
    for (cnt = 0; cnt < NUM_CARDS; ++cnt)
    {
        if (cards[SUIT][cnt] != suit) flush    = FALSE;
    }
    for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt)
    {
        if (cards[CARD][cnt] != cards[CARD][cnt+1]-1) straight = FALSE;
    }
    /*
    // If we get here, we only have a flush or a straight.  Check
    // the values of both.
    */
    if ((flush == TRUE) && (straight == FALSE))
    {
            write("FLUSH!");
            payoff(FLUSH);
    }
    else if ((straight == TRUE) && (flush == FALSE))
    {
            write("STRAIGHT!");
            payoff(STRAIGHT);
    }

    /*
    // If we don't have a flush or a straight, then we might as well
    // rule out a royal flush and a royal straight check.  We only need
    // to be concerned about two of a kind, three of a kind, two pair,
    // four of a kind or full house.

    */
    else if ((!flush) && (!straight))
    {
        /*
        // Check to see if we have a four of a kind.
        */
        if ((cards[CARD][0] == cards[CARD][3]) ||
            (cards[CARD][1] == cards[CARD][4]))
        {
            write("FOUR OF A KIND!");
            payoff(FOURKIND);
        }
        /*
        // Check to see if we have a full house.
        */
        else if (((cards[CARD][0] == cards[CARD][1])  &&
                  (cards[CARD][2] == cards[CARD][4])) ||
                 ((cards[CARD][0] == cards[CARD][2])  &&
                  (cards[CARD][3] == cards[CARD][4])))
        {
            write("FULL HOUSE!");
            payoff(FULLHOUSE);
        }
        /*
        // Check to see if we have three of a kind.
        */
        else if ((cards[CARD][0] == cards[CARD][2]) ||
            (cards[CARD][1] == cards[CARD][3]) ||
            (cards[CARD][2] == cards[CARD][4]))
        {
            write("THREE OF A KIND!");
            payoff(THREEKIND);
        }
        else
        {   
            /*
            // Now perform a simple for loop through the cards.
            // Depending on the ident value, we will have a different
            // answer.  If you try this out on a piece of paper with
            // any set, you'll notice that the only ambiguous case
            // is between three of a kind and two pair, but we handle
            // three of a kind before we reach this case.
            */
            ident = 1;
            for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt)
            {
                if (cards[CARD][cnt] == cards[CARD][cnt+1])
                {
                    ident = ident + 1;
                }
            }    
            /*
            // Check to see if we have two of a kind. (Jacks or better)
            */
            if (ident == 2)
            {
                flag = TRUE;
                for (cnt = 0; cnt < NUM_CARDS - 1; ++cnt)
                {
                    if ((cards[CARD][cnt] == cards[CARD][cnt+1])
                        && (cards[CARD][cnt] < JACK))
                    {
                        flag = FALSE;

                   }
                }    
                if (flag)
                {
                    write("TWO OF A KIND!");
                    payoff(TWOKIND);
                }
                else
                {   
                    write("You have nothing in your hand.  The game ");
                    write("takes your coins.\n(You must have Jacks or ");
                    write("better for a pair.)\n");
                    payoff(NOTHING);
                }
            }    
            /*
            // Check to see if we have two pair.
            */
            else if (ident == 3)
            {
                write("TWO PAIR!");
                payoff(TWOPAIR);
            }
            else
            {   
                write("You have nothing in your hand.  The game ");
                write("takes your coins.\n");
                payoff(NOTHING);
            }
        }    
    }    
    else
    {   
        /*
        // We also have to check for straight flush and royal flush.
        */
        if ((flush == TRUE) && (straight == TRUE))
        {
            /*
            // Check to see if we have a royal flush (*lucky bastard*)
            */
            if (cards[CARD][0] == TEN)
            {
                write("ROYAL FLUSH!!!");
                payoff(ROYALFLUSH);
            }
            /*
            // Check to see if we have a straight flush (*lucky bastard*)
            */
            else
            {   
                write("STRAIGHT FLUSH!!\n");
                payoff(STRFLUSH);
            }
        }    
    }    
}

/*
// discard_second(str) -- Check for discards, and give out new cards.
*/
discard_second(str)
{

    int suit, number, cnt, loop, loop2;
    string arr;

    /*
    // If we get a null string, they want to keep their cards.
    */
    if (str == "")
    {
        /*
        // Keep the cards, and check for a win.
        */
        write("\nOkay, keeping cards.\n");
        write("\nYour second set of cards are:\n\n");
        write_cards();
        check_win();
        exit_out();
        return 1;
    }
    /*
    // If we get to this point, we separate out their answers by
    // spaces, and then change the card for each inputted answer.
    // If we have a bad answer, then we want to just exit out.
    // Don't take away coins, but don't give any payoff.
    */

    /*
    // Use explode to the the numbers into an array of strings.
    */
    str = str + " ";
    arr = explode(str, " ");
    loop = sizeof(arr); loop = loop - 1;

    /*
    // While we have a number of items in our array, go through all
    // of them.  Use sscanf() to get the number in the array, and
    // assign a free card to that spot in the card set.
    */
    while (loop >= 0)
    {
        /*
        // Convert the string number to an integer (atoi()!  Gotta have it.)
        */
        if (sscanf(arr[loop], "%d", cnt) != 1)
        {
            write("Bad entry of discard cards.  All bets are off.\n");
            exit_out();
            return 1;
        }
        /*
        // This is so we don't get a number out of range.
        */
        if ((cnt < 1) || (cnt > NUM_CARDS))
        {
            write("Bad entry of discard cards.  All bets are off.\n");
            exit_out();
            return 1;
        }
        /*
        // Assign the card.
        */
        cnt = cnt - 1; loop2 = FALSE;
        while (!loop2)
        {

            suit   = get_suit();
            number = get_number();
            if (!deck[suit][number])
            {
                deck[suit][number] = 1;
                cards[SUIT][cnt] = suit;
                cards[CARD][cnt] = number;
                loop2 = TRUE;
            }
        }    
        loop = loop - 1;
    }
    /*
    // Sort the cards, show the cards, and check for a win.
    */
    /* sort_cards(); */
    write("\nYour second set of cards are:\n\n");
    write_cards();
    check_win();
    exit_out();
    return 1;
}

/*
// play(str) -- Play a game of poker.
*/
play(str)
{
    if (str != "poker")
    {
        return 0;
    }
    if (this_player()->query_money() < 10)
    {
        write("You don't have the money!\n");
        return 1;
    }
    if (!playerob)
    {
        playerob = this_player();
    }
    else
    {   
        write(capitalize(playerob->query_name()) + " is playing poker.  ");
        if (playerob->query_gender() == "male")
        {
            write("Wait until he is done.\n");
        }
        else if (playerob->query_gender() == "female")
        {
            write("Wait until she is done.\n");
        }
        else
        {   
            write("Wait until it is done.\n");
        }
        return 1;
    }
    say(capitalize(playerob->query_name())
                   + " plays a game of poker on the poker machine.\n");
    this_player()->add_money(-10);
    write("You drop 10 coins into the machine.\n");
    call_out("clean_player", MAX_TIME);

    playerob = this_player();
    /*
    // Clean up the cards.
    */
    clean_cards();

    /*
    // Check to see if we need to reshuffle.  If not, we just increment
    // the shuffle count for next time.  Otherwise, we call clean_deck()
    // and reshuffle.
    */
    if (SHUFFLECNT == shuffle)
    {
        write("The dealer reshuffles the deck.\n");
        clean_deck(); shuffle = 1;
    }
    else
    {   
        shuffle = shuffle + 1;
    }
    /*
    // Print out the cards, and ask for discards.
    */
    write("The machine deals you some cards:\n\n"); deal(); write("\n");
    write("Which ones would you like to discard? [<RETURN> for none]\n");
    write("Cards to discard [separated by spaces] -> ");
    input_to("discard_second");
    return 1;
}
