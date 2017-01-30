#include "defs.h"


#define DEALER "dealer"+TPRN
#define HOUSE_LIMIT 16
#define DECKS 6

inherit ROOM;

mapping hand;
mapping bet;
mixed *deck;
int bank;

void build_deck();
int shuffle_deck();
int display_deck();
display_hand();
display_dealer();
void end_round();
void deal_card(string play);
int point_total(string str);

void reset(int arg) {
  bank=2000;
  if(arg) return;
  set_light(1);
  short_desc=HIY+"Casino"+NORM;
  long_desc=
"  This part of the tavern is well-decorated with persian carpets and\n"+
"brass fittings.  Scattered about the floor are several tables where\n"+
"gamblers play their games, groaning and shouting in jubilation as\n"+
"Lady Luck dictates.\n";
  items=({
    "carpets","Upon closer inspection, the persian carpets appear to be\n"+
              "cheap knock-offs",
    "fittings","The furniture has expensive brass fittings",
    "tables","They appear to be "+BOLD+"play"+NORM+"ing "+BOLD+"blackjack"+NORM,
    "gamblers","It appears to be a mixed crowd of people, with some young sheiks,\n"+
               "a few merchants, and a smatter of peasants",
  });
  dest_dir=({
    PATH+"stav7.c","north",
    PATH+"stav1.c","west",
  });
  hand=([ ]);
  bet=([ ]);
}

void init() {
  ::init();
  if((int)this_player()->query_level() > 20) {
    add_action("shuffle_deck","shuffle");
    add_action("display_deck","dd");
  }
  add_action("blackjack","play");
}

int blackjack(string str) {
  int max;
  if(str != "blackjack") {
    notify_fail("Play what?\n");
    return 0;
  }
  max=bank;
  if((int)TP->query_money() < bank)
    max=(int)TP->query_money();
  write("\nHow much do you bet? (max "+max+")\n");
  input_to("bj_bet");
  return 1;
}

void bj_bet(string str) {
  bet[TPRN]=atoi(str);
  if( bet[TPRN] == 0) {
    write("That is not a valid bet.\n");
    return;
  }
  if(bet[TPRN] < 0) {
    write("The dealer spits in your face!\n");
    return;
  }
  if(bet[TPRN] > (int)TP->query_money()) {
    write("You do not have that much money.\n");
    return;
  }
  if(bet[TPRN] > bank) {
    write("You cannot bet larger than the bank.\n");
    return;
  }
  bank += bet[TPRN];
  TP->add_money(-bet[TPRN]);
  deal_card(TPRN);
  deal_card(TPRN);
  deal_card(DEALER);
  deal_card(DEALER);
  write("  The dealer deals you your hand.\n");
  display_hand();
  display_dealer();
  write("Would you like another card? ");
  input_to("bj_deal");
}

void bj_deal(string str) {
  if(member_array(str,({ "y", "Y", "yes","Yes","YES" })) != -1) {
    deal_card(TPRN);
    display_hand();
    if(point_total(TPRN) > 21) {
      write("You busted!\n");
      end_round();
      return;
    }
    if(point_total(DEALER) < HOUSE_LIMIT) {
      deal_card(DEALER);
      write("  The dealer takes a card.\n");
      display_dealer();
      if(point_total(DEALER) > 21) {
        write("  The dealer busted.  You win "+bet[TPRN]+" coins!\n");
        TP->add_money(2*bet[TPRN]);
        bank-=2*bet[TPRN];
        end_round();
        return;
      }
    }
    write("Would you like another card? ");
    input_to("bj_deal");
    return;
  }
  while(point_total(DEALER) < HOUSE_LIMIT) {
    deal_card(DEALER);
    write("  The dealer takes a card.\n");
    display_dealer();
    if(point_total(DEALER) > 21) {
      write("  The dealer busted.  You win "+bet[TPRN]+" coins!\n");
      TP->add_money(2*bet[TPRN]);
      bank-=2*bet[TPRN];
      end_round();
      return;
    }
  }
  if(point_total(DEALER) > point_total(TPRN)) {
    write("The house wins.  You lose "+bet[TPRN]+" coins.\n");
  } else
  if(point_total(DEALER) < point_total(TPRN)) {
    write("You win!\n");
    TP->add_money(2*bet[TPRN]);
    bank-=2*bet[TPRN];
  } else {
    write("It is a tie!  The dealer gives you back your money.\n");
    TP->add_money(bet[TPRN]);
    bank-=bet[TPRN];
  }
  end_round();
}

void end_round() {
  hand[TPRN]=({ });
  hand[DEALER]=({ });
  bet[TPRN]=0;
  write("Would you like to play again? (y/n) ");
  input_to("bj_again");
}

void bj_again(string str) {
  if(str=="y" || str=="yes" || str=="Y")
    blackjack("blackjack");
}

void build_deck() {
  string card;
  int d,i,j;
  deck=allocate(52*DECKS);
  for(d=0; d < DECKS; d++) {
    for(i=0; i < 4; i++) {
      for(j=1; j <= 13; j++) {
        switch(i) {
          case 0: card="H"; break;
          case 1: card="C"; break;
          case 2: card="S"; break;
          case 3: card="D"; break;
        }
        switch(j) {
          case 1: card+="A"; break;
          case 11: card+="J"; break;
          case 12: card+="Q"; break;
          case 13: card+="K"; break;
          default: card+=j;
        }
        deck[(d*52)+(i*13)+(j-1)]=card;
      }
    }
  }
  write("The dealer shuffles a new deck.\n");
}

/*
int shuffle_deck() {
  string temp;
  int place;
  int i,size;
  write("Shuffling...");
  for(i=0,size=sizeof(deck); i < size; i++) {
    place=random(52);
    temp=deck[place];
    deck[place]=deck[i];
    deck[i]=temp;
  }
  return 1;
}
*/

void deal_card(string play) {
  string card;
  if(sizeof(deck) < 1)
    build_deck();
  card=deck[random(sizeof(deck))];
  deck-=({ card });
  if(sizeof(hand[play]) > 0)
    hand[play]+=({ card });
  else
    hand[play]=({ card });
}

int display_deck() {
  int i;
  for(i=0; i < 52*DECKS; i++) {
    write(deck[i]);
    if(i!=51) write(",");
    else write(".\n");
  }
  return 1;
}

display_hand() {
  mixed str;
  int i;
  write(TPRN+": ");
  for(i=0; i < sizeof(hand[TPRN]); i++) {
    str=hand[TPRN][i];
    str=str[0..0];
    switch(str) {
      case "S": case "C": write(BOLD+BLK); break;
      case "H": case "D": write(HIR); break;
    }
    write(hand[TPRN][i]+NORM+" ");
  }
  if((int)TP->query_level() > 20)
    write("[Total = "+point_total(TPRN)+"]");
  write("\n");
}

display_dealer() {
  mixed str;
  int i;
  write("Dealer: ");

  str=hand[DEALER][0];
  str=str[0..0];
  switch(str) {
    case "S": case "C": write(BOLD+BLK); break;
    case "H": case "D": write(HIR); break;
  }

  write(hand[DEALER][0]+NORM+" ");
  for(i=1; i < sizeof(hand[DEALER]); i++)
    write("** ");
  if((int)TP->query_level() > 20)
    write("[Total = "+point_total(DEALER)+"]");
  write("\n");
}
  
int point_total(string str) {
  mixed x;
  int total,i,aces;
  for(i=0; i < sizeof(hand[str]); i++) {
    x=hand[str][i]; /* A mapping of an array of strings */
    x=x[1..strlen(x)]; /* A segment of a string */
    switch(x) {
      case "A": aces++; break;
      case "J":
      case "Q":
      case "K": total+=10; break;
      default: total += atoi(x);
    }
  }
  for(i=aces; i > 0; i--)
    if(total+11 <= 21)
      total+=11;
    else
      total+=1;
  return total;
}
