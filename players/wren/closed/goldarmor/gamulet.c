	/* golden armor set - amulet  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("gamulet");
   set_alias("gorget");
   set_short(" "+YEL+"Golden Gorget"+NORM+"   ");                     
   set_long("The "+YEL+"Golden Gorget"+NORM+" of Tintagel. This throat guard carries \n"+
            "markings of both the elven and dwarven gods of vitality. It   \n"+
            "glitters in the light from a fine diamond dust worked into  \n"+
            "the carefully crafted holy symbols. It clasps with a simple  \n"+
            "and sturdy set of pins at the back. You feel the magic within. \n");
   set_ac(2);
   set_type("amulet");
   set_weight(2);
   set_value(600);
}
