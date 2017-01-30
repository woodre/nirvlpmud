#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

set_name("lava man");
set_alias("man");
set_alt_name("lava");
set_race("creature");
set_short(HIR+"Lava man"+NORM);
set_long(
  "An oozing, walking, hot blob of molten lava.\nIt's eyes sparkle deep red.\n");

set_level(17);
set_hp(350+random(36));
set_al(-1000+random(1001));
set_wc(26);
set_ac(12);
set_light(1);
set_aggressive(1);
set_dead_ob(this_object());
}
monster_died() {
tell_room(environment(this_object()),       "The lava man slinks into the ground.\n");
MOCO("/players/jaraxle/3rd/volcano/items/ruby.c"),environment());
return 0; }
