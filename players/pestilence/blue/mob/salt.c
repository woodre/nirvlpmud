#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("salt"); 
  set_alias("salt");
  set_short("Mr. Salt");
  set_long("Mr. Salt is a small little salt shaker, with a face,\n"+
           "and two little arms.\n");
  set_race("seasoning");
  set_gender("male");
  set_level(4);
  set_wc(9);
  set_ac(4);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
 load_chat("Mr. Salt says: i think that food needs a little bit more pepper.\n");
  load_chat("Mr. Salt winks suggestively.\n");
  set_chat_chance(20);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/sgrain.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "A grain of salt falls from Mr. Salt's body as it hits the ground.\n");
return 0; }
