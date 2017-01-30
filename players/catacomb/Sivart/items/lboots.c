inherit "/obj/armor";
#include <ansi.h>

reset(arg) {
  if(arg) return;
  set_name("boots");
  set_short("A pair of "+HIG+"Lizardskin boots"+NORM);
  set_long(
   " A fine pair of boots made from the lizards near the Durkor\n"+
   "city of Sivart.  Along the sides of the boots are the mark \n"+
   "of the Werjor house, a dagger engulfed in flame\n");
  set_type("boots");
  set_ac(1);
  set_weight(2);
  set_value(750);
}
