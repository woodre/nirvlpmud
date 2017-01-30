/*
* this here will control a deck of cards. call the
* function new_deck() and it will reset the deck. add
* an argument 'jokers' to the function to have it include
* 2 jokers.
* get_next() will return the next card as a string and
* clear it from the deck.
* an add_action() of 'flip deck' will be added to flip through the
* deck and display the remaining cards. this can be called if a
   * player gets ahold of the deck. there will also be an add_action()
* for 'shuffle', which will have a random effect of them messing up
* the shuffle and the deck desting.
* other functions:
*   query_deck - returns whole deck as a string array
*   query_position(x) - returns the card in position 'x' as a string.
*   query_card(what) - returns the position number of card 'what'
*   remove_card(what) - removes card 'what' from the deck
*   remove_position(x) - removes card in position 'x' from the deck
*   add_card(what) - adds card 'what' to the end of the deck
*   set_card(x, what) - sets card in position 'x' to 'what'
* started by plasma@nirvana, 6Feb2003.
*/

#include "plasma.h"
inherit "/obj/treasure.c";
string *deck;

reset(int arg) {
   if(arg) return;
   set_id("deck");
   set_short("A deck of playing cards");
   set_weight(1);
   set_value(25);
}

long() {
   write("A standard deck of playing cards.\n"+
      "There are "+sizeof(deck)+" cards left.\n"+
      "You may 'flip' through the 'deck' to see\n"+
      "what cards they are!\n");
   return 1; }

init() {
   ::init();
   add_action("shuffle","shuffle");
   add_action("flip","flip"); }

shuffle() {
   int x;
   string *tmp;
   
   tmp = ({ });
   while(sizeof(deck)) {
      x = random(sizeof(deck));
      tmp += ({ deck[x] });
      deck -= ({ deck[x] }); }
   deck = tmp;
   write("You shuffle the deck.\n");
   say(TPN+" shuffles the deck.\n");
   x = TP->query_attrib("luc");
   if(!random(x)) {
      write("You screw it up!\n");
      tell_room(ENV(TP),"The cards go flying everywhere, and are gone!\n");
      TP->add_weight(-1);
      destruct(TO);
      return 1; }
   return 1; }

flip(arg) {
   int x;
   
   if(arg != "deck") return 0;
   say(TPN+" flips through a deck of playing cards.\n");
   write("You flip through the deck, and see the cards in this order.\n");
   for(x = 0; x < sizeof(deck); x++) write(deck[x]+"\n");
   return 1; }

new_deck(arg) {
   int x, a, b, count, num;
   string suit, face;
   
   num = 52;
   if(arg == "jokers") num = 54;
   deck = ({ });
   deck = allocate(num);
   for(x = 2; x < 15; x++) {
      if(x == 11) face = "Jack";
      if(x == 12) face = "Queen";
      if(x == 13) face = "King";
      if(x == 14) face = "Ace";
      for(a = 0; a < 4; a++) {
         if(!a) suit = "of Spades";
         if(a) suit = "of Clubs";
         if(a == 2) suit = "of Diamonds";
         if(a == 3) suit = "of Hearts";
         b = random(num);
         while(deck[b]) { b = random(num); }
         if(!face) deck[b] = x+" "+suit;
         if(face) deck[b] = face+" "+suit; } }
   
   if(num == 54) {
      b = random(2);
      for(a = 0; a < 2; a++) {
         for(x = 0; x < sizeof(deck); x++) {
            if(!deck[x] && (!b || b == -1)) {
               if(!b) b = 2;
               deck[x] = "Joker Black"; }
            if(!deck[x] && (b > 0)) {
               b = -1;
               deck[x] = "Joker Red"; } } } }
   
   return 1; }

get_next() {
   string card;
   
   card = deck[0];
   deck -= ({ card });
   if(!sizeof(deck)) destruct(TO);
   return card; }

query_deck() { return deck; }
query_position(x) { return deck[x]; }
query_card(what) {
   int x, a;
   
   a = -1;
   for(x = 0; x < sizeof(deck); x++)
   if(deck[x] == what) a = x;
   
   return a; }

remove_card(what) { deck -= ({ what }); if(!sizeof(deck)) destruct(TO); }
remove_position(x) { deck -= ({ deck[x] }); if(!sizeof(deck)) destruct(TO); }
add_card(what) { deck += ({ what }); }
set_card(x, what) { deck[x] = ({ what }); }
