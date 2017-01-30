#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";
string shortstr,longstr;

reset(arg){
if(arg) return;
set_id("bear");
shortstr = "A stuffed grizzly bear";
longstr = "--Not done yet--";
set_short(shortstr);
set_long(longstr);
set_weight(0);
set_value(0);
}

init(){
  add_action("cuddle","cuddle");
}

cuddle(string str){
if(str != "bear"){
  notify_fail("What would you like to cuddle?\n");
  return 0;
}
  write("You start cuddling the bear.\n");
  say(this_player()->query_name()+" starts cuddling "+this_player()->query_possessive()+" bear.\n");
  set_short(shortstr+" (cuddled)");
  set_long(longstr);
return 1;
}

query_invis(){ return 30; }
