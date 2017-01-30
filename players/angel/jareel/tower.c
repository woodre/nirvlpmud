#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  no_clean = 1;
  set_short(BOLD+BLK+"Tower of the Sembrak"+NORM);
  set_alias("tower");
  set_long(
"The Legendary Tower of the Sembrak.  Standing three stories high\n"+
"piercing the Wood canopy, the tower looms menacingly.  The carapace\n"+
"of the structure is piecemealed together with huge flagstones and a\n"+
"flaky black mortar.  The aura of chaos exudes from within it's walls\n"+
"you may 'enter' the tower, but you probably wont survive intact.\n"+    
""+BOLD+RED+"If you die do not whine about it."+NORM+"\n"+
"\n");
}
get() { return 0; }
