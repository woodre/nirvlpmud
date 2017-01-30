#include "/players/snakespear/closed/ansi.h"
inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

set_id("amazonite");
set_alias("qpiece1");
set_short("a fragment of "+HIC+"amazonite"+NORM);
set_long(
   "  A small fragment of amazonite.  This fragment is a bluish green\n"+
   "feldspar that has been known to be worn by gamblers to attract money\n"+
   "luck.  It is also used by anyone taking a chance to ensure success.\n"+
   "Maybe you should sell it, to get your luck in wealth...\n");
set_weight(3);
set_value(300);
}
