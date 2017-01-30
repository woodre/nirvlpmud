#include "/players/francesco/univ/ansi.h"
inherit "/obj/treasure.c";
#define TP this_player()
#define TPN this_player()->query_name()
#define TO this_object()
/*
object player1;

int game_on;
int pos1, pos2, pos3, pos4, pos5;
int strike, ball;
int counter, level, bet;
int guesse1, guesse2, guesse3, guesse4, guesse5;
int i;

string *info;
string levelle;
string guessed;
string output1, output2, output3, output4, output5;
string guess1, guess2, guess3, guess4, guess5;
string name1;
*/

reset(arg){
if (arg) return;
set_id("flier");
set_alias("flier");
set_short(HIG+"A "+HIC+"flier"+HIR+" about"+HIW+" Francesco's"+HIY+" race"+NORM);
set_long(HIB+"A folded flier, made by cardboard, tough and resistant.\n"+
         "It can be 'read'.\n"+NORM);
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
/*
start(arg) {
    if(game_on) {notify_fail("Wait until the current game is over please.\n"); return 0; }
    if(sscanf(arg,"%s %d",levelle,bet)!=2) {
             notify_fail("The syntax is:  mastermind <level> <bet>.\n"); return 0;}
    if(!arg) {notify_fail("The syntax is:  mastermind <level> <bet>.\n"); return 0;}
    if(levelle != "easy" && levelle != "medium" && levelle != "tough") 
      {notify_fail("Please choose the mastermind level: easy, medium or tough.\n"); return 0;} 
    if(bet != 500 && bet != 1000 && bet != 2000) 
      {notify_fail("The allowed bets are 500, 1000 or 2000.\n"); return 0;}   
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
return 1;}
*/

read_book(str) {
     if (!str) {notify_fail("Read what?\n");return 0;}
     if(str == "flier") {
      write("The flier contains several info you can have about the race:\n"+
            "You can:  'read goal'          'read rules'          \n"+
            "          'read rating'        'read prizes'         \n");
     return 1;}
     if(str == "goal") {
     write("     ----------------------------------------------------------\n"+
           "    |          "+HIR+"F R A N C E S C O ' S   C O N T E S T"+NORM+"           |\n"+
           "    |  "+HIW+"The goal of the contest is to make as much as possible"+NORM+"  |\n"+
           "    |  "+HIW+"experience and coins within a set amount of time.   "+NORM+"    |\n"+
           "    |  "+HIW+"There is one basic feature in this contest:  the    "+NORM+"    |\n"+
           "    |  "+HIW+"participants are not allowed to have neither coins  "+NORM+"    |\n"+
           "    |  "+HIW+"nor heals when the race begins.  "+NORM+"                       |\n"+
          "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "rules") {
     write("     ----------------------------------------------------------\n"+
           "    |                 "+HIR+"C O N T E S T   R U L E S  "+NORM+"              |\n"+
           "    |  "+HIW+"When the race starts the players can:               "+NORM+"    |\n"+
           "    |  "+HIW+"       - have any kind of gear                   "+NORM+"       |\n"+
           "    |  "+HIW+"       - not have any heal                          "+NORM+"    |\n"+
           "    |  "+HIW+"       - not have any casheable or barterable item "+NORM+"     |\n"+
           "    |  "+HIW+"       - not have any special item which could let     "+NORM+" |\n"+
           "    |  "+HIW+"         them make easy coins or heals, such as the   "+NORM+"  |\n"+
           "    |  "+HIW+"         stethoscope or other similar objects       "+NORM+"    |\n"+
           "    |  "+HIW+"       - not have any coins                      "+NORM+"       |\n"+
           "    |  "+HIW+"When the race is running the players can:           "+NORM+"    |\n"+
           "    |  "+HIW+"       - party with whomever they like to "+NORM+"              |\n"+
           "    |  "+HIW+"         including pets, mudkids, daemons etc. etc."+NORM+"     |\n"+
           "    |  "+HIW+"         all companions MUST be included in a party"+NORM+"     |\n"+
           "    |  "+HIW+"       - sell every items they accumulated        "+NORM+"      |\n"+
           "    |  "+HIW+"         during the race                          "+NORM+"      |\n"+
           "    |  "+HIW+"       - not receive any item nor coins by any other"+NORM+"    |\n"+
           "    |  "+HIW+"         player, kids, pets, even if they are not"+NORM+"       |\n"+
           "    |  "+HIW+"         participating in the race"+NORM+"                      |\n"+
           "    |  "+HIW+"       - not go and retrieve any item from their "+NORM+"       |\n"+
           "    |  "+HIW+"         lockers or hotel or motel rooms            "+NORM+"    |\n"+
           "    |  "+HIW+"When the race ends the players can:                 "+NORM+"    |\n"+
           "    |  "+HIW+"       - not sell their items anymore            "+NORM+"       |\n"+
           "    |  "+HIW+"       - (must) have at least the same gear they    "+NORM+"    |\n"+
           "    |  "+HIW+"         had when the race started                  "+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
     if(str == "rating") {
     write("     ----------------------------------------------------------\n"+
           "    |              "+HIR+"F I N A L   R A T I N G          "+NORM+"           |\n"+
           "    |    "+HIW+" The final rating will be calculated according        "+NORM+"|\n"+
           "    |    "+HIW+" to the following basic rules:                     "+NORM+"   |\n"+
           "    |    "+HIW+" experience will be counted as:                    "+NORM+"   |\n"+
           "    |    "+HIY+"               exp_gained / player_level              "+NORM+"|\n"+
           "    |    "+HIW+" coins will be counted as:                     "+NORM+"       |\n"+
           "    |    "+HIY+"               coins_earned / player_level     "+NORM+"       |\n"+
           "    |    "+HIW+" These two figures will be summed and the total   "+NORM+"    |\n"+
           "    |    "+HIW+" will make the list of the winners         "+NORM+"           |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }

     if(str == "prizes") {
     write("     ----------------------------------------------------------\n"+
           "    |      "+HIR+"       C O N T E S T    P R I Z E S"+NORM+"                 |\n"+
           "    |  "+HIW+"   The winners will have three choices:       "+NORM+"          |\n"+
           "    |  "+HIW+"   1) have a legal personalized item               "+NORM+"     |\n"+ 
           "    |  "+HIW+"   2) have half of the exp gotten during the race    "+NORM+"   |\n"+
           "    |  "+HIW+"   3) have half of the coins gotten during the race"+NORM+"     |\n"+
           "    |  "+HIW+"   Best qualified will choose first, then the others"+NORM+"    |\n"+
           "     ----------------------------------------------------------\n");
     return 1; }
return 1;}

/*
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
  zero();
return 1;}

review(){
    if(!game_on) {notify_fail("The game had not started yet.\n"); return 0;} 
    if(TP != player1) return 0;  
   write("Your previous attempts have been:\n");
   for(i=0; i < sizeof(info); i++){write(info[i]);}
return 1;}

win3(){
   write_file("/players/francesco/log/mastermindcol", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 4)  {congrats(); player1->add_exp(bet*3/2);}
         else sorry();
  game_on = 0;
  info = ({ });
  zero();
return 1;}

win4(){
   write_file("/players/francesco/log/mastermindcol", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 5)  {congrats(); player1->add_exp(bet*3);}
         else sorry();
  game_on = 0;
  info = ({ });
  zero();
return 1;}

win5(){
   write_file("/players/francesco/log/mastermind", ctime(time())+"  "+TPN+
             "    Mastermind level "+level+" in "+counter+" attempts\n");    
       if(counter <= 6)  {congrats(); player1->add_exp(bet*4);}
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
*/
    
