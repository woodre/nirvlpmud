/*
Holy symbol of the maiden.
Needed for a quest.  Found in the orc camp in Caladon.
*/

#include "/players/feldegast/defines.h"

inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("symbol");
  set_alias("holy symbol of the maiden");
  set_short(HIY+"Symbol of the Maiden"+NORM);
  set_long("This is the holy symbol of the goddess known as The Maiden.  It is\n"+
           "made of gold and is quite pleasing to look upon.\n");
  set_weight(2);
  set_value(1000);
}
