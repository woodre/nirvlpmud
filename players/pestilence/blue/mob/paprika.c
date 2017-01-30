#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("paprika"); 
  set_alias("paprika");
  set_short("baby Paprika");
  set_long("Baby Paprika is a small little paprika shaker, with a face,\n"+
           "and two little arms.  She is a smaller than her parents Mr. Salt and Mrs. Pepper.\n");
  set_race("seasoning");
  set_gender("female");
  set_level(3);
  set_wc(7);
  set_ac(4);
  set_hp(45);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
  load_chat("Paprika says: when am i gonna get a new brother, mommy?\n");
  set_chat_chance(20);
  load_a_chat("Paprika says: why are you hurting me\n");
  load_a_chat("Paprika cries.\n");
 set_a_chat_chance(30);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/dpaprika.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "As Paprika falls to the ground a dash of paprika falls from the shaker.\n");
return 0; }
