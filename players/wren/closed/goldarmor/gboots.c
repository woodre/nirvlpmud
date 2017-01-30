	/* golden armor set - boots  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("gboots");
   set_alias("boot");
   set_short(" "+YEL+"Golden Boots"+NORM+"    ");                     
   set_long("The "+YEL+"Golden Boots"+NORM+" of Tintagel. These boots are made\n"+
            "of a very dense leather with plates of the same brilliant \n"+
            "gold as the other components of this armor. They rise to \n"+
            "just below the knee and have been built carefully to be  \n"+
            "kind to the foot for long marches. They show little wear. \n");
   set_ac(2);
   set_type("boots");
   set_weight(2);
   set_value(600);
}
