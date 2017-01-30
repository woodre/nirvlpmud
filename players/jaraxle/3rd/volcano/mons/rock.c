#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

set_name("rock man");
set_alias("rock");
set_alt_name("rock man");
set_race("creature");
set_short("Rock man");
set_long(
  "A large boulder with feet and arms like a human.\nIt has a tiny head with eyes crested deep within it.\n");

set_level(17);
set_hp(350+random(51));
set_al(-1000+random(1001));
set_wc(22);
set_ac(20);
set_aggressive(0);
set_dead_ob(this_object());
}
monster_died(){
tell_room(environment(this_object()),       "Rock man crubles into a pile of rubble.\n");
MOCO("/players/jaraxle/3rd/volcano/items/diamond.c"),environment());
return 0; }
