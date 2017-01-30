/* Heal found on ~/dark/mons/vampire.c - nonstorable */

#include "/players/snow/closed/cyber/color.h"
#define TP this_player()

query_save_flag() { return 1; }
id(str) { return str == " vampire soul" || str == "soul"; }
short() { return BOLD+"DarK SouL"+OFF; }
long() { write(
    "    This is the soul of a vampire. If you were to 'merge' it to your\n\
     wounds, you would be swiftly healed... but not without a price.\n");
    return 1; }
weight() { return 1; }
get() { return 1; }
can_put_and_get() { return 1; }
value() { return 500; }
init() {
  if(TP->query_real_name() == "snowtest" ||
     TP->query_level() > 20) add_action("merge_soul","merge");
}

merge_soul(str) {
  if(!str) { write("Merge what? <soul>\n"); return 0; }
  if(str == "soul") {
    write("You merge the vampire soul to your essence...\n");
  say(capitalize(this_player()->query_real_name())+
    " merges a "+BOLD+"DarK SouL"+OFF+" to "+
  this_player()->query_possessive()+" essence.\n");
  this_player()->heal_self(75);
  return 1; }
}
