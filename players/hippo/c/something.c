#include "/players/hippo/bs.h"
inherit"obj/monster";
int i;
reset(arg) {
::reset(arg);
if(arg) return;
set_name ("something");
set_short("An unrecognizable something");
set_long("What the hell is this?? You can't imagine that it was once food."+BS);
set_level(17);
set_wc(25);
set_ac(14);
set_hp(400);
add_money(1700+random(400));    /* Fred */
  }
