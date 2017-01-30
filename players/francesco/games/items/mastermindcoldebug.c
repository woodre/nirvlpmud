#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()

object player1;

int game_on;
int pos1, pos2, pos3, pos4, pos5;
int strike, ball;
int counter, level, bet;
int guesse1, guesse2, guesse3, guesse4, guesse5;
int i;
int time1, time2, time_diff;

string *info;
string levelle;
string guessed;
string output1, output2, output3, output4, output5;
string guess1, guess2, guess3, guess4, guess5;
string name1;

reset(arg){
if (arg) return;
set_id("table");
set_alias("table");
set_short(HIG+"A "+HIC+"'colored"+HIR+" mastermind'"+HIW+" table"+NORM);
set_long(HIB+"This is a wooden table, covered with a soft green felt, with\n"+
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
      pos1= (random(7)+1);
      pos2= (random(7)+1);
      pos3= (random(7)+1);
      if(level == 4) pos4= (random(7)+1);
      if(level == 5) {pos4= (random(7)+1);pos5= (random(7)+1);}
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
            "          'read levels'        'read prizes'        'read colors' \n"+
            "          'read example 1'     'read example 2'     'read example 3'\n");
     return 1;}
     if(str == "rules") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   R U L E S"+NORM+"             |\n"+
           "    |  "+HIW+"The goal of the game is to guess a predefined set of "+NORM+"   |\n"+
           "    |  "+HIW+"colors within as few attempts as possible.  The set is"+NORM+"  |\n"+
           "    |  "+HIW+"made by some different colors, from a table of nine."+NORM+"    |\n"+
           "    |  "+HIW+"The same color will never appear twice in the solution. "+NORM+"|\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"The number of colors in the set to guess are chosen"+NORM+"     |\n"+
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
     if(str == "colors") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   C O L O R S"+NORM+"           |\n"+
           "    |    "+HIW+"                                                      "+NORM+"|\n"+
           "    | "+HIW+"   There are 9 colors, taken from the following table:"+NORM+"   |\n"+
           "    |    "+HIW+"                                                      "+NORM+"|\n"+
           "    |  "+HIW+"   "+NORM+WHT+"@  white (w)"+NORM+HIG+"     @  green  (g)"+NORM+HIR+"     @  red  (r)"+NORM+"       |\n"+
           "    |  "+HIW+"   "+NORM+HIB+"@  blue  (b)"+NORM+HIY+"     @  yellow (y)"+NORM+HIM+"     @  pink (p)"+NORM+"       |\n"+
           "    |  "+HIW+"   "+NORM+HIC+"@  cyan  (c)"+NORM+YEL+"     @  hunter (h)"+NORM+MAG+"     @  maroon (m)"+NORM+"     |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     
     if(str == "prizes") {
     write("     ----------------------------------------------------------\n"+
           "    |    "+HIR+"M A S T E R M I N D   F E E S   A N D   P R I Z E S"+NORM+"   |\n"+
           "    |  "+HIW+"                             experience given "+NORM+"          |\n"+
           "    | "+HIW+" colors are guessed    "+HIR+"easy         "+HIC+"medium       "+HIY+"tough"+NORM+"   |\n"+ 
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
           "    |  "+HIC+"to guess the colors for his/her own pleasure . "+NORM+"         |\n"+
           "    |    "+HIW+"                                              "+NORM+"        |\n"+
           "    |  "+HIW+"Note to healer guild members:                        "+NORM+"   |\n"+
           "    |  "+HIW+"for your guild the experience awarded might change   "+NORM+"   |\n"+
           "    |  "+HIW+"a bit, due to your special way of calculating it.    "+NORM+"   |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "example 3") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #3"+NORM+"         |\n"+
           "    | "+HIB+" The colors to guess are "+HIR+"@ "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+HIC+"@ "+NORM+"                        |\n"+
           "    | "+HIW+" Your try: "+HIY+"@ "+MAG+"@ "+HIR+"@ "+NORM+WHT+"@ "+HIW+"-> two numbers are out of position"+NORM+"    |\n"+
           "    | "+HIW+" Your try: "+HIG+"@ "+NORM+WHT+"@ "+HIR+"@ "+NORM+HIM+"@ "+HIW+"-> one in the right position, one out"+NORM+" |\n"+
           "    | "+HIW+" Your try: "+HIR+"@ "+NORM+WHT+"@ "+HIG+"@ "+NORM+MAG+"@ "+HIW+"-> two in the right position, one out"+NORM+" |\n"+
           "    | "+HIW+" Your try: "+HIC+"@ "+HIR+"@ "+NORM+WHT+"@ "+MAG+"@ "+HIW+"-> four numbers out of position"+NORM+"       |\n"+
           "    | "+HIW+" Your try: "+HIR+"@ "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+HIC+"@ "+HIW+"-> you won!                           "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIG+" How it will be displayed to you:                     "+NORM+"   |\n"+
           "    | "+HIY+" Attempt #1  Your guess -> "+HIY+"@ "+MAG+"@ "+HIR+"@ "+NORM+WHT+"@ "+HIW+"   in = 0  out = 2   "+NORM+" |\n"+
           "    | "+HIY+" Attempt #2  Your guess -> "+HIG+"@ "+NORM+WHT+"@ "+HIR+"@ "+NORM+MAG+"@ "+HIW+"   in = 1  out = 1   "+NORM+" |\n"+
           "    | "+HIY+" Attempt #3  Your guess -> "+HIR+"@ "+NORM+WHT+"@ "+HIW+"@ "+NORM+MAG+"@ "+HIW+"   in = 2  out = 1   "+NORM+" |\n"+
           "    | "+HIY+" Attempt #4  Your guess -> "+HIC+"@ "+HIR+"@ "+NORM+WHT+"@ "+MAG+"@ "+HIW+"   in = 0  out = 4   "+NORM+" |\n"+
           "    | "+HIY+" Attempt #5  Your guess -> "+HIR+"@ "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+HIC+"@ "+HIW+"   in = 4  out = 0"+NORM+"    |\n"+
           "    | "+HIW+" You solved the mastermind game!                        "+NORM+" |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 1") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #1 "+NORM+"        |\n"+
           "    | "+HIB+" The colors to guess are "+HIR+"@ "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+HIC+"@."+NORM+"                        |\n"+
           "    | "+HIW+"Your try: "+HIY+"@ "+MAG+"@ "+HIR+"@ "+NORM+WHT+"@ "+HIW+"The "+HIY+"@ "+HIW+"is not in the number to guess.   "+NORM+"|\n"+
           "    | "+HIW+"                  The "+MAG+"@ "+HIW+"is in the number to guess. "+NORM+"      |\n"+
           "    | "+HIW+"                  The "+HIR+"@ "+HIW+"is not in the number to guess. "+NORM+"  |\n"+
           "    | "+HIW+"                  The "+NORM+WHT+"@ "+HIW+"is in the number to guess. "+NORM+"      |\n"+
           "    | "+HIY+"            The game master will say: 2 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIW+"Your try: "+HIG+"@ "+NORM+WHT+"@ "+HIR+"@ "+NORM+HIM+"@ "+HIW+"The "+HIG+"@ "+HIW+"is not in the number to guess.  "+NORM+" |\n"+
           "    | "+HIW+"                  The "+NORM+WHT+"@ "+HIW+"is in the number to guess and "+NORM+"   |\n"+
           "    | "+HIW+"                        in the correct position."+NORM+"         |\n"+
           "    | "+HIW+"                  The "+HIR+"@ "+HIW+"is in the number to guess but"+NORM+"    |\n"+
           "    | "+HIW+"                        not in the correct position."+NORM+"     |\n"+
           "    | "+HIW+"                  The "+NORM+HIM+"@ "+HIW+"is not in the number to guess. "+NORM+"  |\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      1 out_of_place."+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 2") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #2 "+NORM+"        |\n"+
           "    | "+HIB+" The colors to guess are "+HIR+"@ "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+HIC+"@."+NORM+"                        |\n"+
           "    | "+HIW+" Your try: "+NORM+WHT+"@ "+NORM+MAG+"@ "+NORM+MAG+"@ "+NORM+HIM+"@ "+HIW+"The "+NORM+WHT+"@ "+HIW+"is in the number to guess but"+NORM+"   |\n"+
           "    | "+HIW+"                         not in the correct position."+NORM+"    |\n"+
           "    | "+HIW+"                   The "+NORM+MAG+"@ "+HIW+"is in the number to guess but"+NORM+"   |\n"+
           "    | "+HIW+"                         not in the correct position."+NORM+"    |\n"+
           "    | "+HIW+"                   The "+NORM+MAG+"@ "+HIW+"is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                         in the correct position."+NORM+"        |\n"+
           "    | "+HIW+"                   The "+NORM+HIM+"@ "+HIW+"is not in the number to guess."+NORM+"  |\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      2 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIG+" You might also type in a guess with repeated digits."+NORM+"    |\n"+
           "    | "+HIG+" But, beware, using twice the same digit in your guess"+NORM+"   |\n"+
           "    | "+HIG+" might me helpful yet might be confusing."+NORM+"                |\n"+
           "     ----------------------------------------------------------\n");
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
           "    |    "+HIC+"(3, 4 or 5 letters separated by spaces, respectively)"+NORM+" |\n"+
           "     ---------------------------------------------------------- \n");
     return 1; }
return 1;}

guess(str) {
  guess1 = 0;
  guess2 = 0;
  guess3 = 0;
  guess4 = 0;
  guess5 = 0;
  guesse1 = 0;
  guesse2 = 0;
  guesse3 = 0;
  guesse4 = 0;
  guesse5 = 0;
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if (!str) {notify_fail("Type your guess, please.\n"); return 0;}
    if(TP != player1) return 0;
    if(sscanf(str,"%s %s %s",guess1,guess2,guess3)==level || 
       sscanf(str,"%s %s %s %s",guess1,guess2,guess3,guess4)==level ||
       sscanf(str,"%s %s %s %s %s",guess1,guess2,guess3,guess4, guess5)==level) {
    if(guess1=="r") {guesse1=1; output1=HIR+"@ "+NORM;}
    if(guess1=="g") {guesse1=2; output1=HIG+"@ "+NORM;}
    if(guess1=="y") {guesse1=3; output1=HIY+"@ "+NORM;}
    if(guess1=="b") {guesse1=4; output1=HIB+"@ "+NORM;}
    if(guess1=="p") {guesse1=5; output1=HIM+"@ "+NORM;}
    if(guess1=="c") {guesse1=6; output1=HIC+"@ "+NORM;}
    if(guess1=="w") {guesse1=7; output1=WHT+"@ "+NORM;}
    if(guess1=="h") {guesse1=8; output1=YEL+"@ "+NORM;}
    if(guess1=="m") {guesse1=9; output1=MAG+"@ "+NORM;}
    if(guess2=="r") {guesse2=1; output2=HIR+"@ "+NORM;}
    if(guess2=="g") {guesse2=2; output2=HIG+"@ "+NORM;}
    if(guess2=="y") {guesse2=3; output2=HIY+"@ "+NORM;}
    if(guess2=="b") {guesse2=4; output2=HIB+"@ "+NORM;}
    if(guess2=="p") {guesse2=5; output2=HIM+"@ "+NORM;}
    if(guess2=="c") {guesse2=6; output2=HIC+"@ "+NORM;}
    if(guess2=="w") {guesse2=7; output2=WHT+"@ "+NORM;}
    if(guess2=="h") {guesse2=8; output2=YEL+"@ "+NORM;}
    if(guess2=="m") {guesse2=9; output2=MAG+"@ "+NORM;}
    if(guess3=="r") {guesse2=1; output3=HIR+"@ "+NORM;}
    if(guess3=="g") {guesse2=2; output3=HIG+"@ "+NORM;}
    if(guess3=="y") {guesse3=3; output3=HIY+"@ "+NORM;}
    if(guess3=="b") {guesse3=4; output3=HIB+"@ "+NORM;}
    if(guess3=="p") {guesse3=5; output3=HIM+"@ "+NORM;}
    if(guess3=="c") {guesse3=6; output3=HIC+"@ "+NORM;}
    if(guess3=="w") {guesse3=7; output3=WHT+"@ "+NORM;}
    if(guess3=="h") {guesse3=8; output3=YEL+"@ "+NORM;}
    if(guess3=="m") {guesse3=9; output3=MAG+"@ "+NORM;}    
    if(guess4=="r") {guesse4=1; output4=HIR+"@ "+NORM;}
    if(guess4=="g") {guesse4=2; output4=HIG+"@ "+NORM;}
    if(guess4=="y") {guesse4=3; output4=HIY+"@ "+NORM;}
    if(guess4=="b") {guesse4=4; output4=HIB+"@ "+NORM;}
    if(guess4=="p") {guesse4=5; output4=HIM+"@ "+NORM;}
    if(guess4=="c") {guesse4=6; output4=HIC+"@ "+NORM;}
    if(guess4=="w") {guesse4=7; output4=WHT+"@ "+NORM;}
    if(guess4=="h") {guesse4=8; output4=YEL+"@ "+NORM;}
    if(guess4=="m") {guesse4=9; output4=MAG+"@ "+NORM;}
    if(guess5=="r") {guesse5=1; output5=HIR+"@ "+NORM;}
    if(guess5=="g") {guesse5=2; output5=HIG+"@ "+NORM;}
    if(guess5=="y") {guesse5=3; output5=HIY+"@ "+NORM;}
    if(guess5=="b") {guesse5=4; output5=HIB+"@ "+NORM;}
    if(guess5=="p") {guesse5=5; output5=HIM+"@ "+NORM;}
    if(guess5=="c") {guesse5=6; output5=HIC+"@ "+NORM;}
    if(guess5=="w") {guesse5=7; output5=WHT+"@ "+NORM;}
    if(guess5=="h") {guesse5=8; output5=YEL+"@ "+NORM;}
    if(guess5=="m") {guesse5=9; output5=MAG+"@ "+NORM;}
    write("1="+pos1+"  2="+pos2+"  3="+pos3+"  4="+pos4+"   5="+pos5+"\n");    

    check_win();}
    else
    {notify_fail("There must be "+level+" digits, separated by spaces.\n");return 0;}
    time1=time();
return 1; }

check_win() {
  strike = 0;
  ball = 0;
  guessed = 0;
  if(guesse1 == pos1) strike++;
  if(guesse2 == pos2) strike++;
  if(guesse3 == pos3) strike++;
  if(level == 4) {if(guesse4 == pos4) strike++;}
  if(level == 5) {if(guesse4 == pos4) strike++; if(guess5 == pos5) strike++;}
  if(guesse1 == pos2 || guesse1 == pos3 || guesse1 == pos4 || guesse1 == pos5) ball++;
  if(guesse2 == pos1 || guesse2 == pos3 || guesse2 == pos4 || guesse2 == pos5) ball++;
  if(guesse3 == pos1 || guesse3 == pos2 || guesse3 == pos4 || guesse3 == pos5) ball++;
  if(level == 4) {if(guesse4 == pos1 || guesse4 == pos2 || guesse4 == pos3 || guesse4 == pos5) ball++;}
  if(level == 5) {
             if(guesse4 == pos1 || guesse4 == pos2 || guesse4 == pos3 || guesse4 == pos5) ball++;
             if(guesse5 == pos1 || guesse5 == pos2 || guesse5 == pos3 || guesse5 == pos4) ball++;}
  counter++;
  if(level == 3) guessed =output1+""+output2+""+output3;
  if(level == 4) guessed =output1+""+output2+""+output3+""+output4;
  if(level == 5) guessed =output1+""+output2+""+output3+""+output4+""+output5;
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
  guesse1 = 0;
  guesse2 = 0;
  guesse3 = 0;
  guesse4 = 0;
  guesse5 = 0;
return 1;}
    

test_idle() {
    time2 = time();
    time_diff = time2 - time1;
    if(time_diff <= 600) call_out("test_idle",60);
    else idle_out();
return 1; }
    
idle_out() {
    if(game_on) {
    tell_object(player1,"The time limit for playing a game of Mastermind has been reached.\n");
    zero();  
    return 1; }
return 1;}


get(stri) {
    if(stri == "table") {
     notify_fail("What??  You would like to remove the table?\n");
    return 0;}
return 0;}
