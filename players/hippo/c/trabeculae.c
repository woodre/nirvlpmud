#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("trabeculae");
set_alias("trab");
set_short("Some trabeculae");
set_long(
   "These are some trabeculae, that cause the contracting of the heart."+BS);
set_level(15);
set_hp(225);
set_ac(12);
set_wc(20);
money = 875;
}
