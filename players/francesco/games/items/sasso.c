#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

string name1, name2;
object player1, player2;
string guess1, guess2, button1, button2;
int game_on, time1, time2, time_diff;
int solo;

reset(arg){
if (arg) return;
set_id("table");
set_alias("table");
set_short(HIW+"A 'sasso' table"+NORM);
set_long(HIW+"This is a wooden table, covered with a soft green felt, with\n"+
         "ashtrays at the four corners.  There are also three buttons \n"+
         "to 'push'.  A flier lies on the table and can be 'read'.\n"+NORM);
game_on = 0;
guess1="";
guess2="";
}

init() {
  ::init();
    add_action("read_book","read");
    add_action("push_button", "push");
    add_action("start","sasso");
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
        write("Start playing a game with who?\n");
        return 1; }
    if(!present(arg,environment(TP))) {
        write(capitalize(arg)+" is not present in this room.\n");
        return 1; }    
    player2 = present(arg,environment(TP));
    player1 = TP;
    if(player1->query_money() < 500) {
     write("You do not have enough to start a game.\n");
    return 1; }
     if(arg == "seller" || arg == "Chloe" ){
      solo = 1;
      name1 = player1->query_name();
      name2 = player2->query_name();
      tell_object(player1,"You have invited "+name2+" to a game of Sasso and she accepted. 'push #' to play.\n");
      tell_object(player1,"If you lose, 500 coins will be withdrawn off your score.\n");
      tell_object(player1,"If you feel uncomfortable, you can 'refuse' before 'push'ing.\n");
      time1= time();
      game_on = 1;
      guess2 = (random(3)+1);
      if(guess2 == 1) {guess2 = "1"; button2 = "rock";}
      if(guess2 == 2) {guess2 = "2"; button2 = "paper";}
      if(guess2 == 3) {guess2 = "3"; button2 = "scissors";}
      test_idle();
     return 1;}   
    if(player2->query_money() < 500) {
     write(player2->query_name()+" cannot afford a game.\n");
    return 1; }
    if(player1 == player2) {
      solo = 1;
      name1 = player1->query_name();
      name2 = player2->query_name();
      tell_object(player1,"You are going to play a solo game of Sasso. 'push #' to play.\n");
      tell_object(player1,"If you lose, 500 coins will be withdrawn off your score.\n");
      tell_object(player1,"If you feel uncomfortable, you can 'refuse' before 'push'ing.\n");
      time1= time();
      game_on = 1;
      guess2 = (random(3)+1);
      if(guess2 == 1) {guess2 = "1"; button2 = "rock";}
      if(guess2 == 2) {guess2 = "2"; button2 = "paper";}
      if(guess2 == 3) {guess2 = "3"; button2 = "scissors";}
      test_idle();
     return 1;}   
    name1 = player1->query_name();
    name2 = player2->query_name();
    tell_object(player1,"You have invited "+name2+" to a game of Sasso.\n");
    tell_object(player2,name1+" has invited you to a game of Sasso.\n"+
                "The winner will take 500 coins from the loser.\n"+
                "You can 'accept' or 'refuse'.\n");
    time1= time();
    game_on = 1;
    test_idle();
return 1;}

accept(){
if(!game_on) return;
  if(TP == player2) {
    guess1=0;
    guess2=0;
    time1 = time();
    tell_room(environment(TP),name1+" and "+name2+" start playing a game.\n");
    tell_object(player1,name2+" has accepted to play a game of Sasso with you.\n"+
               "You can push a button to make your choice.\n");
    tell_object(player2,"You accepted to play a game of Sasso with "+name1+".\n"+
               "You can push a button to make your choice.\n");
  return 1; }
return 1; }

refuse() {
if(!game_on) return;
  if(solo) {
    tell_object(player1,"Ok, maybe you want to try again?\n");
  game_on = 0;
  name1= 0;
  name2= 0;
  return 1;}
  if(TP == player2) {
    tell_object(player1,name2+" has refused to play a game of Sasso with you.\n");
    tell_object(player2,"You refused to play a game of Sasso with "+name1+".\n");
  game_on = 0;
  name1= 0;
  name2= 0;
return 1; }
return 1; }
   
read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "flier") {
     write("   ----------------------------------------------------------- \n"+
           "  | "+HIR+"              S A S S O   R U L E S"+NORM+"                       "+NORM+"|\n"+
           "  |                                                           |\n"+
           "  | "+HIW+"Each player pushes a button and will play with that item. "+NORM+"|\n"+
           "  |                                                           |\n"+
           "  | "+HIC+"To play with the rock, push 1.                            "+NORM+"|\n"+
           "  | "+HIC+"To play with the paper, push 2.                           "+NORM+"|\n"+
           "  | "+HIC+"To play with the scissors, push 3.                        "+NORM+"|\n"+
           "  |                                                           |\n"+
           "  | "+HIY+"The scissors will win over the paper.                     "+NORM+"|\n"+
           "  | "+HIY+"The rock will win over the scissors.                      "+NORM+"|\n"+
           "  | "+HIY+"The paper will win over the rock.                         "+NORM+"|\n"+
           "  | "+HIY+"Should both players choose the same, it will be a tie.    "+NORM+"|\n"+
           "  |                                                           |\n"+
           "  | "+HIB+"The winner will take 500 coins from the loser.            "+NORM+"|\n"+
           "  |                                                           |\n"+
           "  | "+HIW+"To start a game: sasso <opponent name>.                   "+NORM+"|\n"+
           "  | "+HIW+"                 sasso <Chloe> (will play against her)    "+NORM+"|\n"+
           "  | "+HIW+"                 sasso <your own name> (solo game)        "+NORM+"|\n"+
           "   ----------------------------------------------------------- \n");
     return 1; }
return 1;}

push_button(str) {
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if (!str) {notify_fail("Push what?\n");return 0;}
    if(TP != player1 && TP != player2) return 0;
     time1 = time();
     if( str == "1") {
     if(TP == player1) {
      guess1=str;
      button1="rock";
     if(guess1 && guess2) check_win();
     return 1;}
     if(TP == player2) {
      button2="rock";
      guess2=str;
     if(guess1 && guess2) check_win();
     return 1;}
    return 1;}
    if( str == "2") {
     if(TP == player1) {
      guess1=str;
      button1="paper";
     if(guess1 && guess2) check_win();
     return 1;}
     if(TP == player2) {
      guess2=str;
      button2="paper";
     if(guess1 && guess2) check_win();
     return 1;}
    return 1;}
    if( str == "3") {
     if(TP == player1) {
      guess1=str;
      button1="scissors";
     if(guess1 && guess2) check_win();
     return 1;}
     if(TP == player2) {
      guess2=str;
      button2="scissors";
     if(guess1 && guess2) check_win();
     return 1;}
    return 1;}
   write("Okay.  Try pushing on a button that exists.\n");
return 1; }

check_win() {
  if(guess1 == "1" && guess2 == "1") tie();
  if(guess1 == "2" && guess2 == "2") tie();
  if(guess1 == "3" && guess2 == "3") tie();
  if(guess1 == "1" && guess2 == "2") win2();
  if(guess1 == "1" && guess2 == "3") win1();
  if(guess1 == "2" && guess2 == "1") win1();
  if(guess1 == "2" && guess2 == "3") win2();
  if(guess1 == "3" && guess2 == "1") win2();
  if(guess1 == "3" && guess2 == "2") win1();
return 1;}

tie(){
  if(solo) write("You pushed the "+button1+" button against the "+button2+" button.  "+HIW+"It is a tie!\n"+NORM);
  else
  tell_room(environment(TP),"Both players pushed the "+button1+" button\n"+
                            "        "+HIW+"It is a tie.\n"+NORM);
  zero();
return 1;}

win1(){
  if(solo) write("You pushed the "+button1+" button against the "+button2+" button.  "+HIW+"You won!\n"+NORM);
  else
  tell_room(environment(TP),name1+" pushed the "+button1+" button.\n"+name2+" pushed the "+button2+" button.\n"+
            "       "+HIW+name1+" won!\n"+NORM);
  player1->add_money(500);
  if(solo == 0) player2->add_money(-500);
  zero();
return 1;}

win2(){
  if(solo) write("You pushed the "+button1+" button against the "+button2+" button.  "+HIW+"You lost!\n"+NORM);
  else
  tell_room(environment(TP),name1+" pushed the "+button1+" button.\n"+name2+" pushed the "+button2+" button.\n"+
            "       "+HIW+name2+" won!\n"+NORM);
  player1->add_money(-500);
  if(solo == 0) player2->add_money(500);
  zero();
return 1;}

zero() {
  game_on = 0;
  guess1 = 0;
  guess2 = 0;
  name1 = 0;
  name2 = 0;
  solo = 0;
return 1;}

test_idle() {
    time2 = time();
    time_diff = time2 - time1;
    if(time_diff <= 60) call_out("test_idle",10);
    else idle_out();
return 1; }
    
idle_out() {
    if(game_on) {
    tell_object(player1,"The time limit for playing a game of Sasso has been reached.\n");
    tell_object(player2,"The time limit for playing a game of Sasso has been reached.\n");
    zero();  
    return 1; }
return 1;}

get(stri) {
    if(stri == "table") {
     notify_fail("What??  You would like to remove the table?\n");
    return 0;}
return 0;}
