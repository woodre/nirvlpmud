	/* golden armor set - helm  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("ghelmet");
   set_alias("helm");
   set_short(" "+YEL+"Golden Helmet"+NORM+"   ");                     
   set_long("The "+YEL+"Golden Helmet"+NORM+" of Tintagel was part of a legendary \n"+
            "armor set that was said to have provided amazing protection\n"+
            "to its barer. It outlives them often. It has delicate \n"+
            "scrolling patterns engraved over all its surfaces. A \n"+
            "simple visor slips down to protect the face.\n");
   set_ac(2);
   set_type("helmet");
   set_weight(1);
   set_value(500);
}
