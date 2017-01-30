#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("pepper"); 
  set_alias("pepper");
  set_short("Mrs. Pepper");
  set_long("Mrs. Pepper is a small little pepper shaker, with a face,\n"+
           "and two little arms.\n");
  set_race("seasoning");
  set_gender("female");
  set_level(4);
  set_wc(9);
  set_ac(4);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
  load_chat("Mrs. Pepper wiggles around you.\n");
  set_chat_chance(20);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/pgrain.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "A grain of pepper falls from Mrs. Pepper's body as it hits the ground.\n");
return 0; }
