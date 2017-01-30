/* Values changed due to upgrade in level of the monster
completed by Pestilence per Dragnar 8-9-2014 */
#define tp this_player()
#define ETP environment(this_player())
#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";

reset(arg) {
set_name("gloves");
set_alias("leather gloves");
set_short(BOLD+"Blackened leather gloves"+NORM);
set_long(
  "These hardened leather gloves provide excellent protection\n"+
  "to the hands and arms nearly to the elbow.  The charred black\n"+
  "leather has seen many battles.  You might also 'barter' them.\n");

set_ac(2);
set_params("magical",1,0,0);
set_params("other|fire",0,10,0);
set_type("gloves"); /* forbin set_type("misc"); */
set_weight(1); /* pain of gloves, should be light -Forbin 2005.04.27 */
set_value(1300);
}


init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int amt;
if(!str || !present("sedjak",ETP)) { write("What?\n"); return 1; }
if(str == "gloves" || str == "leather gloves") {
  if(worn == 1)
  {
    write("You must remove the "+HIR+"gloves"+NORM+" before you can barter them!\n");
    return 1;
  }
  amt = (5200 + random(22000));
  write("Sedjak takes the charred gloves and puts them away.\n"+
        "He hands "+amt+" coins to you and says 'any time, stranger.'\n");
  say("Sedjak puts something away in his chest.\n");
  tp->add_money(amt);
  destruct(this_object());
  return 1; }
}
