	/* golden armor set - shield  */

#include "/players/wren/ansi.h"
inherit "obj/armor";

reset(arg)  {
   if(arg)  return;
   ::reset();
   set_name("gshield");
   set_alias("kite");
   set_short(" "+YEL+"Golden Shield"+NORM+"   ");                     
   set_long("The "+YEL+"Golden Shield"+NORM+" of Tintagel. This teardrop shield is \n"+
            "highly unusual in character. Its size and weight seem light but the   \n"+
            "runes etched all around its edge bare a strong resemblance to dwarven \n"+
            "markings. The surface is a near mirror finish with a thin platinum    \n"+
            "ribbon inset around the edge. Both aeshetically pleasing and useful. \n");
   set_ac(2);
   set_type("shield");
   set_weight(2);
   set_value(800);
}
