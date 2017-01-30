#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("cheese");
set_short("A piece of cheese");
set_long(
   "This is a piece of cheese that doesn't look very dangerous."+BS+
   "It has been srcumbled and swallowed etc.. but you'd better"+BS+
   "watch out, anyway."+BS);
set_level(10);
set_ac(7);
set_wc(15);
set_hp(150);
money = 450;
set_aggressive(1);
}
