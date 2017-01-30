#include "/players/hippo/bs.h"
inherit"obj/monster";
reset(arg) {
::reset(arg);
if(arg) return;
set_name("tobacco");
set_short("An agressive tobacco mosaic");
set_long("This tobacco mosaic caused the bad shape of this lung. You'd"+BS+
  "like to kill it, but it looks dangerous and aggressive."+BS);
set_level(19);
set_al(-1000);
set_wc(28);
set_ac(16);
set_hp(475);
money = 2000;
set_aggressive(1);
}
