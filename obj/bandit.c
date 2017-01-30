#include "std.h"
int is_playing ;
object player, ob;
int counter , score , money , winning;
string string1 , string2 , string3;
/* This is just for me to keep track of how much money I have made.*/
reset(arg) {
 if(arg) {
  return;
        }
 money = 0;
}

init() {
#if 0 /* Rumplemintz */
 add_action("play"); add_verb("play");
#else
  add_action("play", "play");
#endif
}

id(str) { return str == "bandit"; }

short() {
    return "bandit";
}

long() {
    write("This is the money-eating bandit.\n");
    write("It is bolted to the floor.\n");
    write("There is a list of the possible wins nailed to it.\n");
    write("<!!!> <!!!> <!!!>    ==       2 goldcoins.\n");
    write("<@@@> <@@@> <@@@>    ==       7 goldcoins.\n");
    write("<###> <###> <###>    ==      17 goldcoins.\n");
    write("<~~~> <~~~> <~~~>    ==      37 goldcoins.\n");
    write("<$$$> <$$$> <$$$>    ==     237 goldcoins.\n");
    write("<+++> <+++> <+++>    ==    1237 goldcoins.\n");
    write("<^^^> <^^^> <^^^>    ==  21 237 goldcoins.\n");
    write("<&&&> <&&&> <&&&>    ==  51.237 goldcoins.\n");
    write("<***> <***> <***>    == 151.237 goldcoins.\n");
    write("< :) > < :) > < :) > == 551.237 goldcoins.\n");
    if (is_playing)
write("But it is currently being played upon by " +        call_other(player,"query_name",0) + " \n");
}

query_value() { return 10000; }


get() { return 0; }

play(str) {
 if(str != "bandit")
  return 0;

 if( call_other("players/akane/casino","query_free",0) < 1) {
  write("They are all occupied now. \n");
  write("You have to wait for your turn. \n");
  return 1;
 }
 if (is_playing )
  return 0;
 if (call_other(this_player(), "query_money", 0) < 3){
  write("Hey Bozo , broke people don't belong here ! ");
                say(call_other(this_player(), "query_name",0) +      " inserted some cash into the bandit.\n");
  return 1;
 }
 call_other("players/akane/casino","set_free",-1);
 is_playing = 1 ;
 player = this_player();
 call_other(this_player(), "add_money", -3);
 say(call_other(this_player(), "query_name", 0) +      " inserted some cash into the bandit.\n");
 write("You expectantly put 3 coins into the machine.\n");
 /* Not a real bandit , but I didn't like to delve to deep into
    probability calculations. */
        score = random(1000000);
 will_we_win();
 counter = 0;
 set_heart_beat(1);
 return 1;
}

/* Nice outprint with one effect at a time. */

heart_beat()
{

 counter +=1 ;

 if(counter == 1)
  tell_object(player,string1 + " ");
 if(counter == 2)
  tell_object(player,string2 + " ");
 if(counter == 3)
  tell_object(player,string3 + "\n");
 if ( counter > 2) {
  say("The game ends with : " + string1 + " " +
   string2 + " " + string3 + "\n");
   if (winning > 0) {
    tell_object(player,"You win " +
     winning + " goldcoins!\n");
    call_other(player,"add_money",winning);
    say(call_other(player,"query_name") +
     " just won " + winning +
     " goldcoins!!!\n");
   } else
    tell_object(player,"You lost!\n");
  is_playing = 0;
  call_other("players/akane/casino","set_free",1);
  set_heart_beat(0);
 }
 return;
}


will_we_win() {

    int what_string;

 what_string = random(10);
 winning = 0;
 if(score <500000) {
                winning = 5;
  string1 = "<!!!>";
                winning += 10;
  string3 = "<!!!>";
 }
 if( score < 300000) {
                winning += 10;
  string1 = "<@@@>";
  string2 = "<@@@>";
  string3 = "<@@@>";
 }
 if ( score < 230000 ) {
                winning += 20;
  string1 = "<###>";
  string2 = "<###>";
  string3 = "<###>";
 }
 if ( score < 210000 ) {
                       winning += 20;
  string1 = "<~~~>";
  string2 = "<~~~>";
  string3 = "<~~~>";
 }
 if (score < 201000 ) {
                        winning += 400;
  string1 = "<$$$>";
  string2 = "<$$$>";
  string3 = "<$$$>";
 }
 if (score < 200100) {
   winning += 1000;
  string1 = "<+++>";
  string2 = "<+++>";
  string3 = "<+++>";
 }
 if (score < 200010) {
   winning += 20000;
  string1 = "<^^^>";
  string2 = "<^^^>";
  string3 = "<^^^>";
 }
 if (score < 200005) {
   winning += 30000;
  string1 = "<&&&>";
  string2 = "<&&&>";
  string3 = "<&&&>";
 }
 if (score < 200003) {
   winning += 100000;
  string1 = "<***>";
  string2 = "<***>";
  string3 = "<***>";
 }
 if ( score < 200001) {
   winning += 400000;
  string1 = "< :) >";
  string2 = "< :) >";
  string3 = "< :) >";
 }
 if( score < 199999) {
  winning = 0;
 }
 if ( winning == 0 ) {
  if (what_string == 0) {
   string1 = "<***>";
   string2 = "<***>";
   string3 = "<$$$>";
  } else if (what_string == 1) {
   string1 = "<&&&>";
   string2 = "<&&&>";
   string3 = "<***>";
  } else if (what_string == 2) {
   string1 = "<^^^>";
   string2 = "<^^^>";
   string3 = "<!!!>";
  } else if (what_string == 3) {
   string1 = "<$$$>";
  string2 = "<$$$>";
  string3 = "<&&&>";
 } else if (what_string == 4) {
  string1 = "<###>";
  string2 = "<###>";
  string3 = "< :) >";
 } else if (what_string == 5) {
  string1 = "<@@@>";
  string2 = "<@@@>";
  string3 = "<^^^>";
 } else if (what_string == 6) {
  string1 = "<!!!>";
  string2 = "<!!!>";
  string3 = "<@@@>";
 } else if (what_string == 7) {
  string1 = "< :) >";
  string2 = "< :) >";
  string3 = "<===>";
 } else if (what_string == 8) {
  string1 = "<***>";
  string2 = "<^^^>";
  string3 = "<###>";
  } else if (what_string == 9) {
   string1 = "<@@@>";
   string2 = "<!!!>";
   string3 = "<***>";
  }
 }
 money += 2;
 money -= winning;
 if (winning > 30 ) {
  /* If the sysadmin wonders where someone has gotten his
     money from. */
 }
}
