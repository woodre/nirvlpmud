#include "/players/khrell/define.h"
#include "/players/khrell/ansi.h"
inherit "obj/armor";

reset(arg) {
	        if(arg) return; ::reset(arg);

   set_name("cloak of shadows");
   set_alias("cloak");
   set_short(HIK+"Cloak of Shadows"+NORM);
   set_long(
      "This is the dreaded Cloak of Shadows.  Woven from\n"+
      "the hairs of captured elves dipped in a purified\n"+
      "warpstone dye, it seems to draw in the light cloaking\n"+
      "the wearer in darkness.                             \n");  
   set_ac(1);
   set_type("misc");  
   set_weight(1);
   set_value(11150);
   set_light(-1);
   
}
