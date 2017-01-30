inherit "obj/treasure";
#include "/players/pestilence/ansi.h"

reset(arg) {
  if(arg) return;
  set_id("portal");
  set_alias("swirling portal");
  set_short(""+HIK+"A "+HIW+"swirling"+HIK+" portal"+NORM+"");
  set_long(
"This is a "+HIW+"swirling"+HIK+" portal"+NORM+" that leads to many\n"+
"different realms.  For one to use this portal they only need to type\n"+
 "'church' 'portal' 'hotel'\n"
  );
  set_value(0);
}
get() { return 0; }
