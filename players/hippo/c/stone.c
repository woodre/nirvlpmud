#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
object armour;
::reset(arg);
if(arg) return;
set_name ("stone");
set_short("A stone");         
set_long("This is a stone you could find in a kidney, the urine bladder"+BS+
   "or the gall bladder"+BS);
set_level(14);
set_ac(11);
set_wc(18);
set_hp(225);
money = 850;
  }
