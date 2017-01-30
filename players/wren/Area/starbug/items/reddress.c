	/* red gingham dress, muhahaha */

#include <ansi.h>
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("dress");
   set_alias("armor");
   set_short("a "+RED+"R"+WHT+"e"+RED+"d"+WHT+" G"+RED+"i"+WHT+"n"+RED+"g"+WHT+"h"+RED+"a"+WHT+"m "+RED+"d"+WHT+"r"+RED+"e"+WHT+"s"+RED+"s"+NORM+".");
   set_long("You liberated a "+RED+"Red"+NORM+"-checked Gingham Dress from the demented Rimmer. \n"+
            "The holovirus brought out some very strange traits. The \n"+
            "dwarfers got their revenge though in the end. You think it \n"+
            "might provide some protection.\n");
   set_ac(4);
   set_type("armor");
   set_weight(4);
   set_value(1200);
}
