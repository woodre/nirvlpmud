#include "/players/eurale/closed/ansi.h"
inherit "obj/armor";
#define TP this_player()
#define TO this_object()

reset(arg) {
set_name("feathers");
set_alias("sleeves");
set_short(HIR+"fea"+HIG+"the"+HIY+"red"+NORM+" "+HIM+"sle"+
          HIC+"eve"+HIW+"s"+NORM);
set_long(
  "The colorful feathers from the legendary couatl.  They have been\n"+
  "sewn together to create a beautiful set of sleeves.  A very rare\n"+
  "and valuable barterable item.\n");

set_ac(2);
/* set_type("misc"); -changed from misc to ring (similar to bracers) 2005.05.30 Forbin */
set_type("bracelet");
set_weight(1);
set_value(1500);
set_no_clean(1);
}

/*
query_no_save() { return 1; }
*/

init() {
  ::init();
  add_action("Barter","barter");
}

Barter(str) {
int coins;
if(!present("sedjak",environment(TP))) return 0;
  coins = 4750 + random(600);
if(str == "feathers" || str == "sleeves") {
  write("Sedjak claps with delight.  He exclaims, 'I haven't seen\n"+
        "any of those beautiful Couatl feathers in ages and I want\n"+
        "to thank you for bringing them to me.'  And with that, he\n"+
        "hands you "+coins+" coins.\n");
  TP->add_money(coins);
  destruct(TO);
  return 1; }
}
