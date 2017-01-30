#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object heal;
::reset(arg);
if(arg) return;
set_name ("7up");
set_short("Some 7up");
set_long(
   "This bubbling water must be something tasty, according to the "+BS+
   "sound you hear from above. You think it's 7up, although you"+BS+
   "don't like it at all."+BS);
set_level(10);
set_wc(13);
set_ac(9);
money = 30;
set_hp(150);
heal = clone_object("/players/hippo/heals/bubbles");
if (heal) {
   move_object(heal,this_object());
}
  }
