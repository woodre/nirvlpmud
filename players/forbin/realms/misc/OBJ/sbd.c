#include "/players/forbin/ansi.h"

id(str) { return (str == "saddlebagd"); }

query_weight() { return 100000; }

query_value() { return 1; }

init() {
  add_action("cmd_buy","buy");
  add_action("cmd_buy","purchase");
}

cmd_buy(str) {
  int cost, value;

  if (str == "bag" || str == "saddlebag" || str == "saddle bag") {
  value = 2000;
  if(this_player()->query_money() < value) {
    write("You don't have "+value+" coins.\n");
    return 1;
  }
  cost = value;
  if(!call_other(this_player(), "add_weight", call_other("/players/forbin/realms/misc/OBJ/saddlebag.c", "query_weight"))) {  
    write("You cannot carry the saddlebag.\n");
    return 1;
  }
  this_player()->add_money(-cost);
  write("You purchase a leather saddlebag from Da'vvrus.\n");
  say(this_player()->query_name()+" purchases a saddlebag.\n");
  move_object(clone_object("/players/forbin/realms/misc/OBJ/saddlebag.c"), this_player());
  return 1;
  }
}
