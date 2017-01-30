#include "std.h"
int drinks, price;

id(str) { return str == "box" || str == "bandages"; }

reset(arg) {
  if (!arg) drinks = 10;
  price = drinks * 150;
}

long() {
  write("This is a small tin box filled with bandages. Perhaps you could\n"+
  "'bandage <plyr>'. You can also leave out the arguments to fix yourself.\n"+
  "There are ["+drinks+"] bandages remaining.\n");
}

short() { return "A box of Band-Aid bandages ["+drinks+"]"; }

query_save_flag() {return 1;}
query_value() { return price; }

/* Rump
init() { add_action("use", "drink"); }
*/
init() { add_action("use", "drink"); }

use(arg){
object tp;
object victim;
tp = this_player();
  if(!arg) {
    drinks=drinks - 1;
    tp->heal_self(30);
    write("You peel off the backings and patche yourself up.\n"+
          "There are ["+drinks+"] bandages left.\n");
    say(capitalize(tp->query_name()) + " is patched by a small plastic bandage.\n");
  } else {
  victim=find_player(arg);
    if(!present(victim, environment(tp)) || !victim) {
      write("You can only patch players logged in or those in the same room.\n");
      return 1;
    }
  drinks=drinks-1;
  victim->heal_self(30);
  write("You patch up "+(victim->query_name())+".\n"+
  "There are ["+drinks+"] bandages left.\n");
  say(capitalize(tp->query_name())+" patches up "+(victim->query_name())+" with a small plastic bandage.\n");
  }
  if(drinks == 0){
    destruct(this_object());
    write("There are no more bandages left. You finish off the box.\n");
    tp->add_weight(-1);
  }
}

get() { return 1; }
query_weight() { return 1; }
