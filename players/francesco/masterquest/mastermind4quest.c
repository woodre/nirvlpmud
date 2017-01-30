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
/* Changing this variable to m_info because /obj/treasure uses info variable.
 * Dec-5-2009 - Rumplemintz

string *info;

 */
string *m_info;
int i;
string levelle;
int time1, time2, time_diff;
string solution;
int player_level;
string subject;

reset(arg){
if (arg) return;
   ::reset(arg);
set_id("game");
set_alias("mastermind");
set_short(HIR+"A mastermind game"+NORM);
set_long(HIR+"This is a red box.  A flier is attached to it and can be 'read'.\n"+NORM);
m_info = ({ });
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
    if (present("student_fran",environment(this_object())))
       {notify_fail("Playing the mastermind when a student is present? Naaww.\n"); return 0;} 
    player1 = TP;
    if(player1->query_money() < 1000) {
     notify_fail("You do not have enough coinage to start a game.\n");
    return 0; }
      name1 = player1->query_name();
      player1->add_money(-1000);
      tell_object(player1,"You have started playing a game of Mastermind of level tough.\n");
      tell_object(player1,"If you will solve it within the set number of tries you will earn\n"); 
      tell_object(player1,"some credits for the quest.  Remember that the maximum number of guesses\n");
      tell_object(player1,"is 6.  If you feel uncomfortable, you can abandon the game in any moment.\n");
      game_on = 1;
      level=5;
      counter=0;
      m_info =({ });
      make_number();
      time1= time();
      test_idle();
return 1;}

make_number() {
      pos1= (random(9)+1);
      pos2= (random(9)+1);
      pos3= (random(9)+1);
      pos4= (random(9)+1);
      pos5= (random(9)+1);
/*
        write("1="+pos1+"  2="+pos2+"  3="+pos3+"  4="+pos4+"   5="+pos5+"\n");
*/
      if(pos1 == pos2 || pos1 == pos3 || pos1 == pos4 || pos2 == pos3 || pos2 == pos4 || pos3 == pos4 || pos1 == pos5 || pos2 == pos5 || pos3 == pos5 || pos4 == pos5) try_again();
      else {solution=""+pos1+""+pos2+""+pos3+""+pos4+""+pos5+""; 
      write_file("/players/francesco/masterquest/mastermindstart.log",ctime(time())+"  "+TPN+
               " started number masterquest whose solution was "+solution+"\n"); 
}
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
            "          'read example 1'     'read example 2'       'read example 3'\n");
     return 1;}
     if(str == "rules") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   R U L E S"+NORM+"             |\n"+
           "    |  "+HIW+"The goal of the game is to guess a predefined number"+NORM+"    |\n"+
           "    |  "+HIW+"within six attempts.  The number is made by some  "+NORM+"      |\n"+
           "    |  "+HIW+"different digits, in the range 1 to 9.             "+NORM+"     |\n"+
           "    |  "+HIW+"Two digits will never be the same in the solution. "+NORM+"     |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"The number of digits in the number to guess is 5.     "+NORM+"  |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"The solution can be used as a userid               "+NORM+"     |\n"+
           "    |  "+HIW+"for Fran's computer.                                    "+NORM+"|\n"+
           "    |  "+HIW+"                                                    "+NORM+"    |\n"+
           "    |  "+HIW+"Each try has a fixed cost of 1000 coins.            "+NORM+"    |\n"+
           "    |  "+HIW+"                                                      "+NORM+"  |\n"+
           "    |  "+HIW+"There is a time limit of 10 minutes to solve it."+NORM+"        |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "example 3") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #3"+NORM+"         |\n"+
           "    | "+HIB+" The number to guess is 94271."+NORM+"                           |\n"+
           "    | "+HIW+" your try: 12345 -> three numbers are out of position"+NORM+"    |\n"+
           "    | "+HIW+" your try: 14758 -> one in the right position, two out"+NORM+"   |\n"+
           "    | "+HIW+" your try: 94716 -> two in the right position, two out"+NORM+"   |\n"+
           "    | "+HIW+" your try: 47912 -> five numbers out of position"+NORM+"         |\n"+
           "    | "+HIW+" your try: 94271 -> you won!                              "+NORM+"|\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIG+" How it will be displayed to you:                     "+NORM+"   |\n"+
           "    | "+HIY+" Attempt #1  Your guess -> 12345  in = 0  out = 2    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #2  Your guess -> 14758  in = 1  out = 2    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #3  Your guess -> 94716  in = 2  out = 2    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #4  Your guess -> 47912  in = 0  out = 5    "+NORM+"    |\n"+
           "    | "+HIY+" Attempt #5  Your guess -> 94271  in = 5  out = 0    "+NORM+"    |\n"+
           "    | "+HIW+" You solved the mastermind game!                        "+NORM+" |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 1") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #1 "+NORM+"        |\n"+
           "    | "+HIB+" The number to guess is 94271."+NORM+"                           |\n"+
           "    | "+HIW+" Your try: 12345 -> The 1 is in the number to guess. "+NORM+"    |\n"+
           "    | "+HIW+"                    The 2 is in the number to guess. "+NORM+"    |\n"+
           "    | "+HIW+"                    The 3 is not in the number to guess. "+NORM+"|\n"+
           "    | "+HIW+"                    The 4 is in the number to guess. "+NORM+"    |\n"+
           "    | "+HIW+"                    The 5 is not in the number to guess. "+NORM+"|\n"+
           "    | "+HIY+"            The game master will say: 3 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIW+" Your try: 14758 -> The 1 is in the number to guess but"+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                    The 4 is in the number to guess and "+NORM+" |\n"+
           "    | "+HIW+"                      in the correct position."+NORM+"           |\n"+
           "    | "+HIW+"                    The 7 is in the number to guess but"+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                    The 5 is not in the number to guess. "+NORM+"|\n"+
           "    | "+HIW+"                    The 8 is not in the number to guess. "+NORM+"|\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      2 out_of_place."+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "example 2") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"M A S T E R M I N D   E X A M P L E  #2 "+NORM+"        |\n"+
           "    | "+HIB+" The number to guess is 94271."+NORM+"                            |\n"+
           "    | "+HIW+" Your try: 24456 -> The 2 is in the number to guess but "+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                      in the correct position."+NORM+"           |\n"+
           "    | "+HIW+"                   The 4 is in the number to guess and "+NORM+"  |\n"+
           "    | "+HIW+"                      not in the correct position."+NORM+"       |\n"+
           "    | "+HIW+"                   The 5 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIW+"                   The 6 is not in the number to guess. "+NORM+" |\n"+
           "    | "+HIY+"            The game master will say: 1 in_place"+NORM+"         |\n"+
           "    | "+HIY+"                                      2 out_of_place."+NORM+"    |\n"+
           "    | "+HIW+"                                                      "+NORM+"   |\n"+
           "    | "+HIW+" Note: you used a repeated number (the 4).  This is     "+NORM+" |\n"+
           "    | "+HIW+" allowed but not adviced, because it might lead to      "+NORM+" |\n"+
           "    | "+HIW+" misunderstandings.  The game driver checks the 4       "+NORM+" |\n"+
           "    | "+HIW+" for two times and, correctly, reports one in place   . "+NORM+" |\n"+
           "    | "+HIW+" and one out of place.                                  "+NORM+" |\n"+
           "    | "+HIG+" Beware, using twice the same digit in your guess     "+NORM+"   |\n"+
           "    | "+HIG+" might me helpful yet might be confusing."+NORM+"                |\n"+
           "     ------------------------------------------------------------\n");
     return 1; }
     if(str == "syntax") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"M A S T E R M I N D   S Y N T A X"+NORM+"           |\n"+
           "    |    "+HIG+"To start a game:  mastermind            "+NORM+"              |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIW+"To review your previous guesses:  review"+NORM+"              |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIY+"To abandon the game:  I suck"+NORM+"                          |\n"+
           "    |    "+HIW+"                                        "+NORM+"              |\n"+
           "    |    "+HIC+"To input your guess:  guess # # # # #        "+NORM+"         |\n"+
           "    |    "+HIC+"(5 digits separated by spaces)                      "+NORM+"  |\n"+
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
  if(guess4 == pos4) strike++; 
  if(guess5 == pos5) strike++;
  if(guess1 == pos2 || guess1 == pos3 || guess1 == pos4 || guess1 == pos5) ball++;
  if(guess2 == pos1 || guess2 == pos3 || guess2 == pos4 || guess2 == pos5) ball++;
  if(guess3 == pos1 || guess3 == pos2 || guess3 == pos4 || guess3 == pos5) ball++;
  if(guess4 == pos1 || guess4 == pos2 || guess4 == pos3 || guess1 == pos5) ball++;
  if(guess5 == pos1 || guess5 == pos2 || guess5 == pos3 || guess5 == pos4) ball++;
  counter++;
  guessed =guess1+""+guess2+""+guess3+""+guess4+""+guess5;
  m_info += ({"Attempt #"+counter+"   Your guess -> "+guessed+"   [in_place "+strike+"]   [out_of_place "+ball+"]\n"});
  for(i=0; i < sizeof(m_info); i++){write(m_info[i]);}
  if(strike==level){win();};
return 1;}

review(){
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if(TP != player1 && TPN != "Francesco" ) return 0;   
   write("Your previous attempts have been:\n");
   for(i=0; i < sizeof(m_info); i++){write(m_info[i]);}
return 1;}

win(){
   write_file("/players/francesco/log/mastermind", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 6) congrats(); 
       else sorry();
  game_on = 0;
  m_info = ({ });
  zero();
return 1;}

congrats() {
    write_file("/players/francesco/masterquest/mastermind.log",ctime(time())+"  "+TPN+
               "    Masterquest in "+counter+" attempts, solution was "+solution+"\n"); 
    tell_room(environment(TP),"\n\nDING DING DING, the mastermind buzzes all over.....\nDING DING DING\n\n"+
                              "A student then arrives and yells:\n"+
                              ""+name1+" stole my boss' computer userid!!!!\n"+
                              "I will report his name to officials!\n"+NORM);
       destruct(present("silent"));
       if (!present("student_fran",environment(this_object()))) 
        {
          player_level=TP->query_level() + TP->query_extra_level();
          move_object(clone_object("/players/francesco/masterquest/questmonster.c"),environment(this_object()));  
        }
         present("student_fran",environment())->set_argomento(solution);
         present("student_fran",environment())->set_level1(player_level);
       destruct(this_object());
return 1;}

sorry() {
    tell_object(player1,""+TPN+",  you have solved the mastermind at quest level\n");
    tell_object(player1,"in "+counter+" attempts.  You did well, but not well enough.\n");
    tell_object(player1,"It is therefore impossible to credit you any experience.\n");
    write_file("/players/francesco/masterquest/mastermind.log",ctime(time())+"  "+TPN+
               "    Masterquest in "+counter+" attempts, solution was "+solution+"\n"); 
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

