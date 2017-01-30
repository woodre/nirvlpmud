#include "/players/jaraxle/define.h"
inherit "/players/vertebraker/closed/std/monster.c";

reset(arg)  {
     ::reset(arg);
  if(arg) return;

set_name(BLK+BOLD+"Rat"+NORM);
set_alias("tower rat");
set_alt_name("rat");
set_race("creature");
set_short(BLK+BOLD+"Tower rat"+NORM);
set_long(
   "A small, dirty rat which lives in the crevices of the old tower.\n");
set_level(2);
set_hp(30);
set_al(-100);
set_wc(6);
set_ac(3);
set_wander(11, 0, ({ "out","north","south" }));
set_dead_ob(this_object());
MOCO("/players/jaraxle/templar/invite.c"),TO);
}

monster_died() {
  tell_room(environment(this_object()),
     "The rat twitches violently to it's demise.\n");
return 0; }
