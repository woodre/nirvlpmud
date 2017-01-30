#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) return;
set_name("tooth");
set_short("A cutting tooth");
set_long(
  "This is the first incisor. It looks like a sharp tooth, watch"+BS+
   "out, it might hurt you...."+BS);
set_level(12);
set_ac(9);
set_wc(16);
set_hp(180);
armour = clone_object("players/hippo/armour/glazour_coat");
if (armour) {
   move_object(armour,this_object());
}
  }
