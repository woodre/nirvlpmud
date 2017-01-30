#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

object player1, player2;
int game_on, time1, time2, time_diff;
int summa;
string name1, name2;
string guess1, guess2;
string cast1, cast2;

reset(arg){
    if (arg) return;
   
set_id("table");
set_alias("table");
set_short(HIR+"A 'morra' table"+NORM);
set_long(HIW+"This is a wooden table, covered with a soft green felt, with\n"+
         "ashtrays at the four corners.  A flier lies on the table and\n"+
         "can be 'read'.\n"+NORM);
}

init() {
  ::init();
    add_action("read_book","read");
    add_action("start","morra");
    add_action("cast","cast");
    add_action("guess","guess");
    add_action("accept","accept");
    add_action("refuse","refuse");
if(TP != environment(TO)) 
  return; 
}


start(arg) {
    if(game_on) {
        write("Wait until the current game is over please.\n");
        return 1; }
    if(!arg) {
        write("Start a game with who?\n");
        return 1; }
    if(!present(arg,environment(TP))) {
        write(capitalize(arg)+" is not present in this room.\n");
        return 1; }    
    player2 = present(arg,environment(TP));
    player1 = TP;
    if(player1 == player2) {
        write("Whats the point? You know you're going to win (and lose).\n");
        return 1; }
    if(player1->query_money() < 500) {
     write("You do not have enough to start a game.\n");
    return 1; }
    if(player2->query_money() < 500) {
     write(player2->query_name()+" cannot afford a game.\n");
    return 1; }
    name1 = player1->query_name();
    name2 = player2->query_name();
    tell_object(player1,"You have invited "+name2+" to a game of Morra.\n");
    tell_object(player2,name1+" has invited you to a game of Morra.\n"+
                "The winner will take 500 coins from the loser.\n"+
                "You can 'accept' or 'refuse'.\n");
    time1 = time();
    game_on = 1;
    return 1; }


accept(){
if(!game_on) return;
  if(TP == player2) {
    guess1 = 0;
    guess2 = 0;
    cast1 = 0;
    cast2 = 0;
    time1 = time();
    tell_room(environment(TP),name1+" and "+name2+" start playing a game of Morra.\n");
    tell_object(player1,name2+" has accepted to play a game of Morra with you.\n"+
               "You can 'cast' a number and 'guess' another one.\n");
    tell_object(player2,"You accepted to play a game of Morra with "+name1+".\n"+
               "You can 'cast' a number and 'guess' another one.\n");
  return 1; }
return 1; }

refuse() {
if(!game_on) return;
  if(TP == player2) {
    tell_object(player1,name2+" has refused to play a game of Morra with you.\n");
    tell_object(player2,"You refused to play a game of Morra with "+name1+".\n");
  game_on = 0;
  name1= 0;
  name2= 0;
return 1; }
return 1; }
   
read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "flier") {
      write("You can:  'read rules'  'read examples'   'read syntax'\n");
     return 1;}
     if(str == "rules") {
     write("     -------------------------------------------------------\n"+
           "    |              "+HIR+"M O R R A   R U L E S"+NORM+"                    |\n"+
           "    |  "+HIW+"Each player casts a number and makes a guess."+NORM+"        |\n"+
           "    |  "+HIW+"The cast numbers are added together and"+NORM+"              |\n"+
           "    |  "+HIW+"their sum is checked against each guess."+NORM+"             |\n"+
           "    |  "+HIW+"He who guesses right wins 500 bucks from the other."+NORM+"  |\n"+
           "     -------------------------------------------------------\n");
     return 1; }
     if(str == "examples") {
     write("     -------------------------------------------------------\n"+
           "    |              "+HIR+"M O R R A   E X A M P L E S"+NORM+"              |\n"+
           "    | "+HIW+"                        cast       guess              "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"|\n"+
           "    | "+HIB+"Example 1    Player1     4           9                "+NORM+"|\n"+
           "    | "+HIB+"             Player2     3           5                "+NORM+"|\n"+
           "    | "+HIB+"             Sum         7      Nobody wins.          "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"|\n"+
           "    | "+HIY+"Example 2    Player1     4           9                "+NORM+"|\n"+
           "    | "+HIY+"             Player2     5           7                "+NORM+"|\n"+
           "    | "+HIY+"             Sum         9      Player1 wins.         "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"|\n"+
           "    | "+HIC+"Example 3    Player1     4           9                "+NORM+"|\n"+
           "    | "+HIC+"             Player2     5           9                "+NORM+"|\n"+
           "    | "+HIC+"             Sum         9      It is a tie.          "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"|\n"+
           "    | "+HIW+"Beware, the cast must be within 0-5 range and thus    "+NORM+"|\n"+
           "    | "+HIW+"the guess must be in the range 0-10                   "+NORM+"|\n"+
           "     -------------------------------------------------------\n");
     return 1; }
     if(str == "syntax") {
     write("     -------------------------------------------------------\n"+
           "    |              "+HIR+"M O R R A   S Y N T A X"+NORM+"                  |\n"+
           "    |     "+HIW+"To start a game:  'morra <opponent name>'"+NORM+"         |\n"+
           "    |     "+HIW+"To play:  each player 'cast #' and 'guess #'"+NORM+"      |\n"+
           "    |               "+HIW+"(two separate commands, please)"+NORM+"         |\n"+
           "     ------------------------------------------------------- \n");
     return 1; }
return 1;}

cast(str) {
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if (!str) {notify_fail("Cast what?\n");return 0;}
    if(TP != player1 && TP != player2) return 0;
    if(str != "0" && str != "1" && str != "2" && str != "3" && str != "4" && str != "5") {
        write("Okay.  Cast number must be within 0 and 5.\n");
        return 1; }
    time1 = time();
    if(TP == player1) {
     cast1=str;
     check_done();
    return 1;}
    if(TP == player2) {
     cast2=str;
    check_done();
    return 1;}
return 1; }

guess(str) {
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if (!str) {notify_fail("Guess what?\n");return 0;}
    if(TP != player1 && TP != player2) return 0;
    if(str != "0" && str != "1" && str != "2" && str != "3" && str != "4" && str != "5" && str != "6" && str != "7" && str != "8" && str != "9" && str != "10") {
        write("Okay.  Guessed number must be within 0 and 10.\n");
    return 1; }
    time1 = time();
    if(TP == player1) {
     guess1=str;
     check_done();
    return 1;}
    if(TP == player2) {
     guess2=str;
    check_done();
    return 1;}
return 1; }

check_done() {
  if( guess1 && guess2 && cast1 && cast2 ) check_win();
return 1;}

check_win() {
  summa = atoi(cast1) + atoi(cast2);
  if( game_on != 0 && summa == atoi(guess1) && summa == atoi(guess2)) tie();
  if( game_on != 0 && summa != atoi(guess1) && summa != atoi(guess2) ) nobody();
  if( game_on != 0 && summa == atoi(guess1) ) win1();
  if( game_on != 0 && summa == atoi(guess2) ) win2();
return 1;}

tellroom() {
   tell_room(environment(TP),name1+" cast "+cast1+" and guessed "+guess1+".\n"+
                             name2+" cast "+cast2+" and guessed "+guess2+".\n"+
                            "The sum of "+cast1+" + "+cast2+" is "+summa+".\n");
return 1;}

nobody() {
  tellroom();
  tell_room(environment(TP),"        Nobody won.\n");
  zero();
return 1;}
 
tie(){
  tellroom();
  tell_room(environment(TP),"        It is a tie.\n");
  zero();
return 1;}

win1(){
  tellroom();
  tell_room(environment(TP),HIW+"        "+name1+" won!\n"+NORM);
  player1->add_money(500);
  player2->add_money(-500);
  zero();
return 1;}

win2(){
  tellroom();
  tell_room(environment(TP),HIW+"        "+name2+" won!\n"+NORM);
  player1->add_money(-500);
  player2->add_money(500);
  zero();
return 1;}

zero() {
  game_on = 0;
  guess1 = 0;
  guess2 = 0;
  cast1 = 0;
  cast2 = 0;
  summa = 0;
  name1 = 0;
  name2 = 0;
return 1; }

test_idle() {
    time2 = time();
    time_diff = time2 - time1;
    if(time_diff <= 60) call_out("test_idle",10);
    else idle_out();
return 1; }
    
idle_out() {
    if(game_on) {
    tell_object(player1,"The time limit for playing a game of Morra has been reached.\n");
    tell_object(player2,"The time limit for playing a game of Morra has been reached.\n");
    zero();  
    return 1; }
return 1;}
get(stri) {
    if(stri == "table") {
        notify_fail("What??  You would like to remove the table?\n");
        return 0;
    }
    return 0;
}
