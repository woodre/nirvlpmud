#include "/players/stark/defs.h"
inherit "obj/armor";
reset(arg) {
  if(arg) return;
  set_id("Student Council Jacket");
  set_alias("jacket");
  set_short("Student Council Jacket");
  set_long(
"  This is a uniform of the Ohtori Academy Student Council.  The jacket \n"+
"is white and buttons at the shoulder.  Decorative gold cording falls \n"+
"from the shoulder to the center.  The trim and lining are done in a \n"+
"strawberry red.\n");
  set_ac(2);
  set_type("armor");  /* armor,helmet,boots,ring,amulet,shield,misc  */
  set_weight(1);
  set_value(1200);
}
