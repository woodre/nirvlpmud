#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";

reset(arg){
  if(arg) return;
set_id("fountain");
set_short("A "+HIC+"crystal clear"+OFF+" fountain"+OFF);
set_long("This wonderful fountain sprays water from the mouth of\n"+
         "a sculpted turtle resting upon seashells.  Small fish swim \n"+
         "around the coins that rest upon the bottom of the fountain\n"+ 
         "as wishes from past travelers.  You can 'drink' from the \n"+
         "water of this work of art as you make a small wish or 'wish'\n"+
         "for something.\n");
    call_out("echos",random(20));
}
get(){ return 0; }

init(){
    add_action("wish","wish");
    add_action("drink_water","drink");
    add_action("resting","rest");
    add_action("resting","relax");
}

resting(){
   write("You sit down and take a huge sigh of relief.\n");
   say(this_player()->query_name()+" sits down and takes a huge sigh of relief.\n");
   return 1;
}

exit(){
}

wish(string str){
int amt;
string wish;
  if(!str){
    write("Usage: wish <amount> <wish>\n");
    return 1;
  }
  if(sscanf(str,"%d %s",amt,wish) != 2){
    write("Usage: wish <amount> <wish>\n");
    return 1;
  }
if(amt < 0) amt = -(amt);
if(this_player()->query_money() < amt){
  write("You do not have that many coins to wish with.\n");
  return 1;
}
write("You toss in "+amt+" coins and make a wish.\n");
say(this_player()->query_name()+" tosses in "+amt+" coins to the pool and makes a wish.\n");
this_player()->add_money(-amt);
write_file("/players/wocket/closed/log/WISHES",this_player()->query_real_name()+" "+str+" "+ctime()+"\n");
return 1;
}

echos(){
    switch(random(4)){
case 0:    say("A gust wind blows and water sprays at you.\n");
           break;
case 1:    say("The fountain sparkles in the sun.\n");
           break;
case 2:    say("Little fish splash up from the water and dive back down.\n");
           break;
case 3:    say("The turtle sputters a bit and water begins to flow again.\n");
           break;
}
call_out("echos",random(150));
 return 1;
}

drink_water(string str){
  if(!str){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
  if(str != "water"){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
  if(this_player()->drink_soft(15) == 0){
    notify_fail("You are to soaked to drink the water.\n");
    return 0;
  }
  if(this_player()->query_money() < 60){
    notify_fail("You dont have enough money to make a wish with.\n");
    return 0;
  }
this_player()->heal_self(5+random(2));
this_player()->add_money(-60);
write("You toss in some money and take a drink of water.\n");
write("You close your eyes and make a wish.\n");
say(this_player()->query_name()+" tosses in some money and takes a drink of water.\n");
say(this_player()->query_name()+" closes "+this_player()->query_possessive()+" eyes.\n");
return 1;
}
