#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object heal;
::reset(arg);
if(arg) return;
set_name("bread");
set_short("A piece of bread");
set_long(
   "This is a piece of bread that doesn't look very dangerous."+BS+
   "It has been srcumbled and swallowed etc.. but you'd better"+BS+
   "watch out, anyway."+BS);
set_level(5);
set_wc(9);
set_ac(5);
set_hp(75);
heal = clone_object("/players/hippo/heals/grain");
if (heal) {
   move_object(heal,this_object());
}
  }
