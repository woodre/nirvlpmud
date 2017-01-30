inherit "obj/monster";
#include "plasma.h"
#define CHIPS present("casino chips",this_player())
#define DECK present("deck",this_object())
#define "/players/boltar/casino/floor/bj_master.c" BJ_MASTER

object *players;
string d_hand, *hands;
int game_on, turn, *bets;

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_name("dealer");
   set_alias("blackjack");
   set_level(25);
   set_wc(15);
   set_ac(30);
   set_al(350);
   set_short("The Blackjack Dealer");
   set_long(
      "This is the blackjack dealer. He's dressed in the casino dealer's\n"+
      "clothing and is very professional. The table rules are as follows:\n"+
      "there are five seats at the table. players may 'sit' to\n"+
      "fill a seat. once they sit there, they have that seat until\n"+
      "they either 'getup' or are kicked off due to idleness. the player\n"+
      "in the first slot can 'start' to start the game moving. anyone in\n"+
      "the room (even non-players) may 'kickoff' the person in the first seat\n"+
      "if they are being idle. this gives a time of 20 seconds. if the game isnt\n"+
      "started within that time, the player forfits their seat.\n"+
      "the game starts. each player antes 100 chips and is dealt 2 cards\n"+
      "face down. the dealer is delt cards in the same fashion. (a player\n"+
      "reaching a total of 21 here automatically wins 1000 chips and is\n"+
      "removed from the rest of the game.) once those cards are dealt,\n"+ 
      "the betting round starts. starting with position 1 and going around\n"+
      "the table, bets are placed. again, a each player has 20 seconds.\n"+
      "If you dont make your bet in that time, forfit your seat.\n\n"+
      "once all bets are placed, the option of 'hit' or 'stand' are given\n"+
      "to each player around the table, starting with position 1 again.\n"+
      "and again, 20 seconds to decide. the player in position 1 may\n"+
      "hit until he decides to stand or until he goes over 21. after his turn,\n"+
      "the next player goes. after all players have either busted or stood, the\n"+
      "dealer reveals his hole card and deals himself cards. he must hit on 16 and\n"+
      "below, must stay on 17 and above.\n\n"+

      "After the dealer has his cards, scores are shown. anyone who has a higher total\n"+
      "than the dealer w/o busting (or anyone who didnt bust when the dealer did) wins\n"+
      "double their bet.\n\n"+

      "After this, the game resets, and the player in position 1 is free to start\n"+
      "a new game.\n");

   set_dead_ob(this_object());
}

monster_died() {
   if(DECK) destruct(DECK);
   return 1; }

init() {
   ::init();
   if(!players) players = ({ 0,0,0,0,0 });
   if(!bets) bets = ({ 0,0,0,0,0 });
   if(!hands) hands = ({ 0,0,0,0,0 });
   add_action("bet","bet");
   add_action("hit","hit");
   add_action("stand","stand");
   add_action("sit","sit");
   add_action("kickoff","kickoff");
   add_action("getup","getup");
   add_action("start","start");
   add_action("view_game","view_game");
   add_action("hand","hand");
}

valid_turn(object who) {
   int x;
   
   if(!who) who = TP;
   x = member(players,who);
   if(x == -1 || x != turn) return 0;
   return 1; }

bet(arg) {
   int x, amt;
   
   if(!valid_turn()) {
      write("And you think its your turn to bet why?\n");
      return 1; }
   if(!game_on) {
      write("A game is not currently in progress.\n"+
         "Please ask the player in Seat 1 to 'start' a game.\n");
      return 1; }
   
   if(bets[turn]) {
      write("You have already placed a bet.\n");
      return 1; }
   
   if(!arg || !sscanf(arg,"%d",amt)) {
      write("You must bet an amount.\n");
      return 1; }
   
   if(amt < 100 || amt > 3000) {
      write("Minimum bet is 100 chips, maximum bet is 3000 chips.\n"+
         "Please try again.\n");
      return 1; }
   
   if(!CHIPS) {
      write("You need some chips!\n");
      return 1; }
   
   if(CHIPS->query_chip_value() < amt) {
      write("You can't cover that bet! cheap skate!\n");
      return 1; }
   
   CHIPS->add_chip_value(-amt);
   bets[turn] = amt;
   write("You place a bet of "+amt+" chips.\n");
   say(TPN+" places a bet of "+amt+" chips.\n",TP);
   remove_call_out("boot_me");
   turn += 1;
   if(turn > sizeof(players) || !players[turn]) {
      game_on = 2; turn = 0;
      tell_object(players[0],"The Dealer awaits your decision.\n");
      return 1; }
   
   call_out("boot_me",50,turn);
   tell_object(players[turn],"The Dealer turns to you and awaits your bet.\n");
   return 1; }

hit() {
   int pts;
   string this_card, this_hand;
   
   if(!valid_turn()) {
      write("You can't get a card quite yet!\n");
      return 1; }
   
   if(game_on != 2) {
      write("Everyone has to bet first!\n");
      return 1; }
   
   remove_call_out("boot_me");
   this_hand = hands[turn];
   this_card = DECK->get_next();
   this_hand += "_"+this_card;
   pts = "/players/boltar/casino/floor/bj_master.c"->check_value(this_hand);
   hands[turn] = this_hand;
   write("The Dealer throws down the "+this_card+" in front of you.\n"+
      "Your total is now: "+pts+".\n");
   say("The Dealer throws down the "+this_card+" in front of "+TPN+".\n",TP);
   if(pts == -1) {
      write("YOU BUST!\n");
      say(TPN+" BUSTS!\n",TP);
      turn += 1;
      if(turn > sizeof(players) || !players[turn]) {
         game_on = 0;
         turn = 0;
         deal_dealer(); }
      return 1; }
   
   call_out("boot_me",50,turn);
   return 1; }

stand() {
   
   if(!valid_turn() || game_on != 2) {
      write("Stand? NOW? You can't do that now! HAHAHA!\n");
      return 1; }
   write("You stand.\n");
   say(TPN+" decides to stand.\n",TP);
   turn += 1;
   remove_call_out("boot_me");
   if(turn > sizeof(players) || !players[turn]) {
      game_on = 0;
      turn = 0;
      deal_dealer(); }
   return 1; }

sit() {
   int x, a;
   
   if(game_on) {
      write("Please wait for the current game to finish.\n");
      return 1; }
   
   if(member(players,TP) > -1) {
      write("You can only occupy one Seat at a time fool!\n");
      return 1; }
   
   a = -1;
   for(x = 0; x < sizeof(players); x++)
   if(!players[x] && a == -1) a = x;
   
   if(a == -1) {
      write("Sorry. The table is full.\n");
      return 1; }
   
   players[a] = TP;
   write("You sit down in Seat "+(a+1)+".\n");
   say(TPN+" sits down in Seat "+(a+1)+".\n",TP);
   return 1; }

kickoff() {
   if(!players[0]) {
      write("There is no one to kick off!\n");
      return 1; }
   
   if(game_on) {
      write("You can't do this during a game!\n");
      return 1; }
   
   call_out("boot_me",50,-1);
   write("You try to boot the player in Seat 1.\n");
   tell_object(players[0],"Someone is trying to boot you! You'd better start a game soon!\n");
   return 1; }

getup() {
   int x;
   
   x = member(players,TP);
   if(x == -1) {
      write("You aren't even sitting down!\n");
      return 1; }
   
   if(turn == x) remove_call_out("boot_me");
   boot_me(x);
   return 1; }

view_game() {
   int x, a;
   string *tmp;
   
   if(game_on != 2) {
      write("No game to view!\n");
      return 1; }
   
   while(players[x]) {
      write("\n\nPlayer: "+CAP(players[x]->query_name())+", Bet: "+bets[x]+"\nHIDDEN\nHIDDEN\n");
      
      tmp = explode(hands[x],"_");
      for(a = 2; a < sizeof(tmp); a++) write(tmp[a]+"\n");
      x += 1; }
   
   write("\n\nPlayer: Dealer\nHIDDEN\n");
   tmp = explode(d_hand,"_");
   for(a = 1; a < sizeof(tmp); a++) write(tmp[a]+"\n\n");
   
   write("Turn: Seat "+(turn+1)+".\n");
   return 1; }

hand() {
   int x;
   string *tmp;
   
   x = member(players,TP);
   if(x == -1 || !game_on) {
      write("You don't have a hand to see....\n");
      return 1; }
   
   tmp = explode(hands[x],"_");
   write("Your hand:\n\n");
   for(x = 0; x < sizeof(tmp); x++)
   write(tmp[x]+"\n");
   
   x = "/players/boltar/casino/floor/bj_master.c"->check_value(hands[member(players,TP)]);
   write("Total: "+x+"\n");
   return 1; }

boot_me(int who) {
   
   if(who == -1) {
      if(players[0] && !game_on) {
         if(find_player(players[0]))
            tell_object(players[0],"You didn't start a game fast enough, and thus lost your Seat.\n");
         tell_room(ENV(TO),"The player in Seat 1 has lost his place.\n"+
            "Take it, hurry!\n");
         players[0] = 0; }
      return 1; }
   
   say("Player "+(who+1)+" waited too long and lost their Seat.\n",players[who]);
   if(players[who])
      tell_object(players[who],"You lost your Seat.\n");
   players[who] = 0;
   if(reorder() == -1) return 1;
   return 1; }

reorder() {
   object *tmp_players;
   string *tmp_hands;
   int x, a, *tmp_bets;
   
   tmp_players = ({ 0,0,0,0,0 });
   tmp_hands = ({ 0,0,0,0,0 });
   tmp_bets = ({ 0,0,0,0,0 });
   
   for(x = 0; x < sizeof(players); x++) {
      if(players[x]) {
         tmp_players[a] = players[x];
         tmp_hands[a] = hands[x];
         tmp_bets[a] = bets[x];
         a += 1; } }
   
   players = tmp_players;
   hands = tmp_hands;
   bets = tmp_bets;
   
   if(!players[0]) {
      tell_room(ENV(TO),"There are no players left. The game ends.\n");
      if(DECK) destruct(DECK);
      move_object(clone_object("/players/boltar/casino/floor/bj_dealer"),ENV(TO));
      destruct(TO);
      return -1; }
   return 1; }

start() {
   int x, a, pts;
   string card;
   object me;
   
   x = member(players,TP);
   if(x) {
      write("Only the player in position 1 may start a game.\n");
      return 1; }
   
   if(game_on) {
      write("A game is already in progress!\n");
      return 1; }
   
   while(x < sizeof(players) && players[x]) {
      me = present("casino chips",players[x]);
      if(!me || me->query_chip_value() < 200) {
         tell_object(players[x],"You can't cover the ante!\n");
         say(TPN+" gets kicked due to being too poor to cover the ante!\n",TP);
         players[x] = 0; }
      if(me && me->query_chip_value() > 199) {
         tell_object(players[x],"You place 100 chips to cover the ante.\n");
         say(TPN+" antes up.\n",players[x]);
         me->add_chip_value(-100); }
      x += 1; }
   x = 0;
   if(reorder() == -1) return 1;
   hands = ({ 0,0,0,0,0 });
   d_hand = "";
   if(DECK)
      destruct(DECK);
   move_object(clone_object("/players/boltar/casino/floor/deck"),TO);
   DECK->new_deck();
   for(a = 0; a < 2; a++) {
      while(x < sizeof(players) && players[x]) {
         me = players[x];
         card = DECK->get_next();
         
         tell_object(me,"The Dealer slides the "+card+" face down to you.\n");
         say("The Dealer slides a card face down to "+CAP(me->query_name())+".\n",me);
         if(!a) {
            hands[x] = "";
            card += "_"; }
         hands[x] += card;
         pts = "/players/boltar/casino/floor/bj_master.c"->check_value(hands[x]);
         if(pts == 21) {
            tell_room(ENV(TO),"\nBLACKJACK!\n\n");
            tell_object(players[x],"You win 1000 chips!\n");
            present("casino chips",players[x])->add_chip_value(1000);
            players[x] = 0;
            if(reorder() == -1) return 1;
            x -= 1; }
         x += 1; }
      card = DECK->get_next();
      if(!a) {
         tell_room(ENV(TO),"The Dealer places his hole card.\n");
         card += "_"; }
      if(a) tell_room(ENV(TO),"The Dealer deals himself the "+card+".\n");
      d_hand += card;
      x = 0; }
   
   game_on = 1;
   turn = 0;
   bets = ({ 0,0,0,0,0 });
   call_out("boot_me",50,turn);
   write("The Dealer turns to you and waits for your bet.\n");
   return 1; }

deal_dealer() {
   int pts;
   string card, *tmp;
   
   pts = "/players/boltar/casino/floor/bj_master.c"->check_value(d_hand);
   
   tmp = explode(d_hand,"_");
   tell_room(ENV(TO),"The Dealer reveals his hole card to be the "+tmp[0]+".\n"+
      "  The Dealer's Score: "+pts+".\n");
   while(pts < 17 && pts != -1) {
      card = DECK->get_next();
      d_hand += "_"+card;
      pts = "/players/boltar/casino/floor/bj_master.c"->check_value(d_hand);
      tell_room(ENV(TO),"The Dealer deals himself the "+card+"\n"+
         "  The Dealer's score: "+pts+"\n"); }
   
   finish_game();
   return 1; }

finish_game() {
   int x, pts, dpts;
   
   dpts = "/players/boltar/casino/floor/bj_master.c"->check_value(d_hand);
   if(dpts == -1)
      tell_room(ENV(TO),"THE DEALER BUSTS! EVERYONE'S A WINNER!\n");
   
   while(players[x]) {
      pts = "/players/boltar/casino/floor/bj_master.c"->check_value(hands[x]);
      if(pts < dpts && players[x]) tell_object(players[x],"YOU LOSE!\n");
      if(pts > dpts || (pts != -1 && dpts == -1)) {
         if(players[x] && present("casino chips",players[x])) {
            tell_object(players[x],"The Dealer hands you your winnings of "+(bets[x]*2)+" chips.\n");
            present("casino chips",players[x])->add_chip_value((bets[x]*2)); } }
      if(pts == dpts && pts != -1) {
         if(players[x] && present("casino chips",players[x])) {
            tell_object(players[x],"The Dealer hands you your bet of "+(bets[x]*2)+" chips back.\n");
            present("casino chips",players[x])->add_chip_value(bets[x]); } }
      x += 1; }
   
   game_on = 0;
   remove_call_out("boot_me");
   bets = ({ 0,0,0,0,0 });
   hands = ({ 0,0,0,0,0 });
   d_hand = "";
   turn = 0;
   
   return 1; }
