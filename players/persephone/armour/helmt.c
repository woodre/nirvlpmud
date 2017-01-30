/* Changed value from 6600 to 600 do to this found on a level 15 monster with much coins. -Snow 1/00 */
inherit "obj/armor";
#include "/players/persephone/rooms.h"
reset (arg){
 if(arg) return;
  set_name("helmet");
  set_alias("helm");
  set_short("Overlord's Helmet");
  set_arm_light(1);
  set_long("This is the famous helmet of the world overlord it is reputed\n" +
           "to have mystical powers when worn and seems to emit a soft\n" +
           "magical glow\n\n");
  set_value(600);
  set_weight(1);
  set_ac(1);
  set_type("helmet");
}

