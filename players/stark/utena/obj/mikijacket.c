#include "/players/stark/defs.h"
inherit "obj/armor";
reset(arg) {
  if(arg) return;
  set_id("Student Council Jacket");
  set_alias("jacket");
  set_short("Student Council Jacket");
  set_long(
"  This is a uniform of the Ohtori Academy Student Council.  The jacket \n"+
"is white and buttons at the shoulder.  A blue cord falls from the left \n"+
"shoulder to the left breast pocket.  The trim and lining are done in a \n"+
"sky blue.\n");
  set_ac(2);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1200);
}
