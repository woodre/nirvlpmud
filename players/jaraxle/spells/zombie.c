#include "/players/jaraxle/define.h"
inherit "obj/monster.c";
int x;
reset(arg)  {
  ::reset(arg);
  if(arg) return;

set_name("Lost Soul");
set_alias("soul");
set_alt_name("lost");
set_race("spirit");
set_short("Lost Soul");
set_long(
    "A beautiful looking human female with brownish tanned skin.\nShe is slightly thin, yet muscular.\n");

set_level(2);
set_hp(275);
set_al(0);
set_ac(15);
set_aggressive(1);
set_can_kill(1);
set_wc(20);
set_dead_ob(this_object());

}

monster_died() {
  tell_room(environment(this_object()),
        "The spirit is finally laid to rest\n");
    x = present("corpse",environment(this_object()));
destruct(x);
return 0; }

