#include "/players/fakir/color.h"
inherit "obj/treasure";

reset(arg) {
  if(arg) return;

set_id("rok shell");
set_alias("shell");
set_short("Rok Shell");
set_long(
  "This is the dead and empty shell from the Ballindorok of the wastelands.\n"+
  "All the life has been used up and it is now only of worth to a shop.\n");

set_weight(1);
set_value(5000);
 
}
