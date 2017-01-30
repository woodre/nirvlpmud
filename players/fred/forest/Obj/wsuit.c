inherit "/obj/armor";
#include "/players/fred/ansi.h"

reset(arg) {
  if(arg) return;
  set_name("suit");
  set_alias("wetsuit");
  set_short(MAG+"Wetsuit"+NORM);
  set_long(
  "  A sleak black wetsuit that extends from the neck\n"+
  "down to just above the knees.  There is a purple\n"+
  "strip that goes down each side of the suit.\n");
      
  set_ac(2);
  set_type("armor");
  set_weight(2);
  set_value(800);
}
