#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

string name1;
object player1;
int guess1, guess2, guess3, guess4, guess5;
int game_on;
int pos1, pos2, pos3, pos4, pos5;
int strike, ball;
int counter, guessed, level, bet;
string *info;
int i;
string levelle;
int time1, time2, time_diff;

reset(arg){
if (arg) return;
set_id("table");
set_alias("table");
set_short(HIC+"A 'mastermind' table"+NORM);
set_long(HIC+"This is a wooden table, covered with a soft green felt, with\n"+
         "one single ashtray.  A flier lies on the table and can be 'read'.\n"+NORM);
info = ({ });
}

init() {
  ::init();
    add_action("read_book","read");
    add_action("start","mastermind");
    add_action("refuse","I");
    add_action("review","review");
    add_action("guess","guess");
  if(TP != environment(TO)) 
  return; 
}

start(arg) {
    if(game_on) {notify_fail("Wait until the current game is over please.\n"); return 0; }
    if(sscanf(arg,"%s %d",levelle,bet)!=2) {
             notify_fail("The syntax is:  mastermind <level> <bet>.\n"); return 0;}
    if(!arg) {notify_fail("The syntax is:  mastermind <level> <bet>.\n"); return 0;}
    if(bet < 0) {notify_fail("You must bet a positive number.\n");return 0;}
    if(levelle != "easy" && levelle != "medium" && levelle != "tough") 
      {notify_fail("Please choose the mastermind level: easy, medium or tough.\n"); return 0;} 
    if(levelle == "tough" && TP->query_level() <=9) {
             notify_fail("Mastermind tough is reserved to players of level 10+.\n"); return 0;}
    if(levelle == "medium" && TP->query_level() <=4) {
             notify_fail("Mastermind medium is reserved to players of level 5+.\n"); return 0;}
    if(levelle == "easy" && bet >= 501) {
             notify_fail("At level easy the maximum allowed bet is 500.\n"); return 0;}
    if(levelle == "medium" && bet >= 1001) {
             notify_fail("At level medium the maximum allowed bet is 1000.\n"); return 0;}
    if(levelle == "tough" && bet >= 2001) {
             notify_fail("At level tough the maximum allowed bet is 2000.\n"); return 0;}
    player1 = TP;
    if(player1->query_money() < bet) {
     notify_fail("You do not have enough coinage to start a game.\n");
    return 0; }
      name1 = player1->query_name();
      player1->add_money(-bet);
      tell_object(player1,"You have started playing a game of Mastermind of level "+levelle+".\n");
      tell_object(player1,"If you will solve it within the set number of tries you will earn\n"); 
      tell_object(player1,"some experience.  Remember that the maximum number of tries is\n");
      tell_object(player1,"4, 5 or 6 for easy, medium and tough mastermind, respectively,\n");
      tell_object(player1,"If you feel uncomfortable, you can abandon the game in any moment.\n");
      game_on = 1;
      if(levelle== "easy")   {level = 3; }
      if(levelle== "medium") {level = 4; }
      if(levelle == "tough") {level = 5; }
      counter=0;
      info =({ });
      make_number();
      time1= time();
      test_idle();
return 1;}

make_number() {
      pos1= (random(9)+1);
      pos2= (random(9)+1);
      pos3= (random(9)+1);
      if(level == 4) pos4= (random(9)+1);
      if(level == 5) {pos4= (random(9)+1);pos5= (random(9)+1);}
      write("1="+pos1+"  2="+pos2+"  3="+pos3+"  4="+pos4+"   5="+pos5+"\n");   
      if(level==3) {if(pos1 == pos2 || pos1 == pos3 || pos2 == pos3) try_again();}
      if(level==4) {if(pos1 == pos2 || pos1 == pos3 || pos1 == pos4 || pos2 == pos3 || pos2 == pos4 || pos3 == pos4) try_again();}
      if(level==5) {if(pos1 == pos2 || pos1 == pos3 || pos1 == pos4 || pos2 == pos3 || pos2 == pos4 || pos3 == pos4 || pos1 == pos5 || pos2 == pos5 || pos3 == pos5 || pos4 == pos5) try_again();}
return 1;
}

try_again() {
      pos1 = 0;
      pos2 = 0;
      pos3 = 0;      
      pos4 = 0;
      pos5 = 0;
   make_number();
return 1;
}


refuse(str) {
if(!game_on) return;
  if(TP == player1 && str =="suck") {
    tell_object(player1,"Dont be sad, "+TPN+".  It happens in the best families.\n"+
                        "Maybe you want to try again?\n");
  zero();
  game_on = 0;
  name1= 0;
  return 1;}
return 0; }
   
read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "flier") {
      write("The flier contains several info you can have:\n"+
            "You can:  'read rules'         'read syntax'          \n"+
            "          'read levels'        'read prizes' \n"+
            "          'read example 1'     'read example 2'       'read example 3'\n");
     return 1;}
     if(str == "rules") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   R U L E S"+NORM+"             |\n"+
           "    |  "+HIW+"The goal of the game is to guess a predefined number"+NORM+"    |\n"+
           "    |  "+HIW+"within as few attempts as possible.  The number is"+NORM+"      |\n"+
           "    |  "+HIW+"made by some different digits, in the range 1 to 9."+NORM+"     |\n"+
           "    |  "+HIW+"Two digits will never be the same in the solution. "+NORM+"     |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"The number of digits in the number to guess are chosen"+NORM+"  |\n"+
           "    |  "+HIW+"by the player and will result in an easy, medium or "+NORM+"    |\n"+
           "    |  "+HIW+"tough game.                                          "+NORM+"   |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"A prize will be rewarded or a penalty will be applied"+NORM+"   |\n"+
           "    |  "+HIW+"according to the number of tries needed to solve the"+NORM+"    |\n"+
           "    |  "+HIW+"game and according to the difficulty of the game."+NORM+"       |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"There is a time limit of 10 minutes to solve it."+NORM+"        |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "levels") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   L E V E L S "+NORM+"          |\n"+
           "    |    "+HIW+"The player can choose between three levels."+NORM+"           |\n"+
           "    |    "+HIW+"                                                      "+NORM+"|\n"+
           "    |    "+HIY+"In level easy,   there are three digits to guess."+NORM+"     |\n"+
           "    |    "+HIY+"In level medium, there are four digits to guess."+NORM+"      |\n"+
           "    |    "+HIY+"In level tough,  there are five digits to guess."+NORM+"      |\n"+
           "    |    "+HIW+"                                              "+NORM+"        |\n"+
           "    |    "+HIW+"All players can play the easy one, while           "+NORM+"   |\n"+
           "    |    "+HIW+"the medium is reserved to levels 5+ and            "+NORM+"   |\n"+
           "    |    "+HIW+"the tough one is for levels 10+.                   "+NORM+"   |\n"+
           "    |    "+HIW+"                                              "+NORM+"        |\n"+
           "    |    "+HIC+"Higher the level, higher the prizes!            "+NORM+"      |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "prizes") {
     write("     ----------------------------------------------------------\n"+
           "    |    "+HIR+"M A S T E R M I N D   F E E S   A N D   P R I Z E S"+NORM+"   |\n"+
           "    |  "+HIW+"                             experience given "+NORM+"          |\n"+
           "    | "+HIW+" number is guessed     "+HIR+"easy         "+HIC+"medium       "+HIY+"tough"+NORM+"   |\n"+ 
           "    | "+HIW+" in less than:                                        "+NORM+"   |\n"+
           "    | "+HIR+" five  attempts  ->  "+HIR+"1.5 x bet"+NORM+"                           |\n"+
           "    | "+HIC+" six   attempts  ->                "+HIC+"3 x bet"+NORM+"               |\n"+
           "    | "+HIY+" seven attempts  ->                             "+HIY+"4 x bet"+NORM+"  |\n"+
           "    |  "+HIW+"                                                     "+NORM+"   |\n"+
           "    |  "+HIM+"The 'bet' is the amount of coins a player wants "+NORM+"        |\n"+
           "    |  "+HIM+"to play with.  The player can choose to bet up to 500, "+NORM+" |\n"+
           "    |  "+HIM+"up to 1000 and up to 2000 coins for the three levels "+NORM+"   |\n"+
           "    |  "+HIM+"respectively.                                        "+NORM+"   |\n"+
           "    |    "+HIW+"                                              "+NORM+"        |\n"+
           "    |  "+HIC+"After those number of attempts, there is no more  "+NORM+"      |\n"+
           "    |  "+HIC+"any reward, even though the player can keep playing"+NORM+"     |\n"+
           "    |  "+HIC+"to guess the number for his/her own pleasure . "+NORM+"         |\n"+
           "    |    "+HIW+"                                              "+NORM+"        |\n"+
           "    |  "+HIW+"Note to healer guild members:                        "+NORM+"   |\n"+
           "    |  "+HIW+"for your guild the experience awarded might change   "+NORM+"   |\n"+
           "    |  "+HIW+"a bit, due to your special way of calculating it.    "+NORM+"   |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "example 3") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #3"+NORM+"         |\n"+
           "    | "+HIB+" The number to guess is 9427."+NORM+"                            |\n"+
           "    | "+HIW+" your try: 1234 -> two numbers are out of position"+NORM+"       |\n"+
           "    | "+HIW+" your try: 1475 -> one in the right position, one out"+NORM+"    |\n"+
           "    | "+HIW+" your try: 9471 -> two in the right position, one out"+NORM+"    |\n"+
           "    | "+HIW+" your try: 4792 -> four numbers out of position"+NORM+"          |\n"+
           "    | "+HIW+" your try: 9427 -> you won!                              "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIG+" How it will be displayed to you:                     "+NORM+"   |\n"+
           "    | "+HIY+" Attempt #1  Your guess -> 1234   in = 0  out = 2    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #2  Your guess -> 1475   in = 1  out = 1    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #3  Your guess -> 9471   in = 2  out = 1    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #4  Your guess -> 4792   in = 0  out = 4    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #5  Your guess -> 9427   in = 4  out = 0    "+NORM+"    |\n"+
           "    | "+HIW+" You solved the mastermind game!                        "+NORM+" |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 1") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #1 "+NORM+"        |\n"+
           "    | "+HIB+" The number to guess is 9427."+NORM+"                            |\n"+
           "    | "+HIW+" Your try: 1234 -> The 1 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIW+"                   The 2 is in the number to guess. "+NORM+"     |\n"+
           "    | "+HIW+"                   The 3 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess. "+NORM+"     |\n"+
           "    | "+HIY+"            The game master will say: 2 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIW+" Your try: 1475 -> The 1 is not in the number to guess."+NORM+"  |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                      in the correct position."+NORM+"           |\n"+
           "    | "+HIW+"                   The 7 is in the number to guess but"+NORM+"   |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                   The 5 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      1 out_of_place."+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 2") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #2 "+NORM+"        |\n"+
           "    | "+HIB+" The number to guess is 9427."+NORM+"                            |\n"+
           "    | "+HIW+" Your try: 2445 -> The 2 is in the number to guess but "+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                      in the correct position."+NORM+"           |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                   The 5 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      2 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIG+" You might also type in a guess with repeated digits."+NORM+"    |\n"+
           "    | "+HIG+" But, beware, using twice the same digit in your guess"+NORM+"   |\n"+
           "    | "+HIG+" might me helpful yet might be confusing."+NORM+"                |\n"+
           "     ------------------------------------------------------------\n");
     return 1; }
     if(str == "syntax") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   S Y N T A X"+NORM+"           |\n"+
           "    |    "+HIG+"To start a game:  mastermind easy <bet>"+NORM+"               |\n"+
           "    |    "+HIG+"                  mastermind medium <bet>"+NORM+"             |\n"+
           "    |    "+HIG+"                  mastermind tough <bet>"+NORM+"              |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIW+"To review your previous guesses:  review"+NORM+"              |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIY+"To abandon the game:  I suck"+NORM+"                          |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIC+"To input your guess:  guess # # #     (easy)"+NORM+"          |\n"+
           "    |    "+HIC+"                      guess # # # #   (medium)"+NORM+"        |\n"+
           "    |    "+HIC+"                      guess # # # # # (tough)"+NORM+"         |\n"+
           "    |    "+HIC+"(3, 4 or 5 digits separated by spaces, respectively)"+NORM+"  |\n"+
           "     ---------------------------------------------------------- \n");
     return 1; }
return 1;}

guess(str) {
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if (!str) {notify_fail("Type your guess, please.\n"); return 0;}
    if(TP != player1) return 0;
    if(sscanf(str,"%d %d %d %d %d",guess1,guess2,guess3,guess4,guess5)==level) check_win();
    else
    {notify_fail("There must be "+level+" digits, separated by spaces.\n");return 0;}
    time1=time();
return 1; }

check_win() {
  strike = 0;
  ball = 0;
  guessed = 0;
  if(guess1 == pos1) strike++;
  if(guess2 == pos2) strike++;
  if(guess3 == pos3) strike++;
  if(level == 4) {if(guess4 == pos4) strike++;}
  if(level == 5) {if(guess4 == pos4) strike++; if(guess5 == pos5) strike++;}
  if(guess1 == pos2 || guess1 == pos3 || guess1 == pos4 || guess1 == pos5) ball++;
  if(guess2 == pos1 || guess2 == pos3 || guess2 == pos4 || guess2 == pos5) ball++;
  if(guess3 == pos1 || guess3 == pos2 || guess3 == pos4 || guess3 == pos5) ball++;
  if(level == 4) {if(guess4 == pos1 || guess4 == pos2 || guess4 == pos3 || guess1 == pos5) ball++;}
  if(level == 5) {
             if(guess4 == pos1 || guess4 == pos2 || guess4 == pos3 || guess4 == pos5) ball++;
             if(guess5 == pos1 || guess5 == pos2 || guess5 == pos3 || guess5 == pos4) ball++;}
  counter++;
  if(level == 3) guessed =guess1+""+guess2+""+guess3;
  if(level == 4) guessed =guess1+""+guess2+""+guess3+""+guess4;
  if(level == 5) guessed =guess1+""+guess2+""+guess3+""+guess4+""+guess5;
  info += ({"Attempt #"+counter+"   Your guess -> "+guessed+"   [in_place "+strike+"]   [out_of_place "+ball+"]\n"});
  for(i=0; i < sizeof(info); i++){write(info[i]);}
  if(strike==level){
       if(level == 3) win3();
       if(level == 4) win4();
       if(level == 5) win5();};
return 1;}

review(){
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if(TP != player1 && TPN != "Francesco" ) return 0;   
   write("Your previous attempts have been:\n");
   for(i=0; i < sizeof(info); i++){write(info[i]);}
return 1;}

win3(){
   write_file("/players/francesco/log/mastermind", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 4 ) {
        congrats(); 
        if(present("healerob",this_player())) player1->add_xp(bet*3/2*6);
          else
        player1->add_exp(bet*3/2);}
       else sorry();
  quest_check();
  game_on = 0;
  info = ({ });
  zero();
return 1;}

win4(){
   write_file("/players/francesco/log/mastermind", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 5)  {
        congrats(); 
        if(present("healerob",this_player())) player1->add_xp(bet*3*6);
          else
        player1->add_exp(bet*3);}
         else sorry();
  quest_check();
  game_on = 0;
  info = ({ });
  zero();
return 1;}

win5(){
   write_file("/players/francesco/log/mastermind", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 6)  {
        congrats(); 
        if(present("healerob",this_player())) player1->add_xp(bet*4*6);
          else
        player1->add_exp(bet*4);}
         else sorry();
  quest_check();
  game_on = 0;
  info = ({ });
  zero();
return 1;}

congrats() {
    write_file("/players/francesco/games/items/mastermindlog/"+TPN,ctime(time())+"  "+TPN+
               "    Mastermind level "+level+" in "+counter+" attempts\n"); 
    tell_room(environment(TP),"    "+HIW+name1+" solved the mastermind game!\n"+NORM);
return 1;}

sorry() {
    tell_object(player1,""+TPN+",  you have solved the mastermind of level "+levelle+"\n");
    tell_object(player1,"in "+counter+" attempts.  You did well, but not well enough.\n");
    tell_object(player1,"It is therefore impossible to credit you any experience.\n");
return 1;}         

zero() {
  game_on = 0;
  guess1 = 0;
  guess2 = 0;
  guess3 = 0;
  guess4 = 0;
  guess5 = 0;
return 1;}

test_idle() {
    time2 = time();
    time_diff = time2 - time1;
    if(time_diff <= 600) call_out("test_idle",60);
    else idle_out();
return 1; }
    
idle_out() {
    if(game_on) {
    zero();  
    if(player1){
    tell_object(player1,"The time limit for playing a game of Mastermind has been reached.\n");}
    return 1; }
return 1;}

    
get(stri) {
    if(stri == "table") {
     notify_fail("What??  You would like to remove the table?\n");
    return 0;}
return 0;}


quest_check() {
   object ob;
   if(bet == 500 && levelle == "easy") {
     if(!present("quest11n",TP)) {
       ob= clone_object("players/francesco/games/items/quest11n.c");
       move_object(ob,TP);
     return 1; }
     if(!present("quest12n",TP)) {
       ob= clone_object("players/francesco/games/items/quest12n.c");
       move_object(ob,TP);
     return 1; }
   return 1; }
   if(bet == 1000 && levelle == "medium") {
     if(!present("quest21n",TP)) {
       ob= clone_object("players/francesco/games/items/quest21n.c");
       move_object(ob,TP);
     return 1; }
     if(!present("quest22n",TP)) {
       ob= clone_object("players/francesco/games/items/quest22n.c");
       move_object(ob,TP);
     return 1; }
   return 1; }
    if(bet == 2000 && levelle == "tough") {
     if(!present("quest31n",TP)) {
       ob= clone_object("players/francesco/games/items/quest31n.c");
       move_object(ob,TP);
     return 1; }
     if(!present("quest32n",TP)) {
       ob= clone_object("players/francesco/games/items/quest32n.c");
       move_object(ob,TP);
     return 1; }
   return 1; }
return 1;}

    



