#include "/players/forbin/ansi.h"

id(str) { return (str == "machine" || str == "vending machine" ||
                  str == "new machine" || str == "new vending machine" ||
                  str == "livestrongdispenser"); }

query_weight() { return 0; }

query_value() { return 1; }

short() { return HIY+"A "+HIW+"New"+HIY+" Vending Machine"+NORM; }

long() {
  write(
    "A temporary vending machine set up to sell a very special item for a\n"+
    "limited time.  During the Tour de France [July 3-25], you may purchase\n"+
    "a LIVESTRONG bracelet.  Support Lance Armstrong as he attempts to win\n"+
    "an unprecedented sixth Tour victory.  And support "+HIW+"WWW."+HIY+"LIVESTRONG"+HIW+".ORG"+NORM+".\n");
  write(
    "             You may buy:\n\n"+
    "           A "+HIW+"LIVE"+HIY+"STRONG"+NORM+" bracelet  :  4500 gold coins\n"+
    "\n");
}

init() {
  add_action("cmd_buy","buy");
  add_action("cmd_buy","purchase");
}

cmd_buy(str) {
  int cost, value;

  if (str == "bracelet" || str == "livestrong" || str == "livestrong bracelet") {
  value = 4500;
  if(this_player()->query_money() < value) {
    write("You don't have "+value+" coins.\n");
    return 1;
  }
  cost = value;
  this_player()->add_money(-cost);
  write("You purchase a yellow livestrong bracelet.\n");
  say(this_player()->query_name()+" purchases a livestrong bracelet.\n");
  move_object(clone_object("/players/forbin/realms/misc/livestrong.c"), this_player());
  return 1;
  }
}
