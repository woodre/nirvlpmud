#include "/players/jenny/define.h"
inherit "/obj/armor.c";
int light=0;

reset(arg) {
   if(arg) return;
   set_name("shoes");
   set_alias("shoe lights");
   set_ac(2);
   set_weight(1);
   set_value(2500);
   set_type("boots");
   set_short(YEL+"Shoe Lights"+NORM);
   
   set_long(
      "Al Bundy invented shoe lights so people could see in the dark.\n"+
      "It was a stupid idea and shoe lights never caught on.\n"+
      "You can "+CYN+"wear shoes"+NORM+" and "+CYN+"toggle light."+NORM+"\n");
}
init() { 
   ::init();
   add_action("use_light","toggle");
}

use_light(arg) {
   if(!arg) { return 0; }
   if(arg == "light") {
      if(light == 0) {
         write("You turn on your "+YEL+"shoe lights"+NORM+", and the room lights up.\n");
         say(TPN+" turns on "+POS+" "+YEL+"shoe lights"+NORM+" and the room lights up.\n");
         light=1;
         set_light(1);
         return 1; }
      if(light == 1) {
         write("You turn off the "+YEL+"shoe lights"+NORM+", and the room becomes darker.\n");
         say(TPN+" turns off "+POS+" "+YEL+"shoe lights"+NORM+" and the room becomes darker.\n");
         light=0;
         set_light(-1);
         return 1; }
   }
}
