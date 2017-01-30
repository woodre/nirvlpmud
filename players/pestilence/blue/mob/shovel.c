#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("shovel"); 
  set_alias("shovel");
  set_short("Shovel");
  set_long("Shovel is a small yellow plastic shovel.  He enjoys filling\n"+
           "Pail up with sand.\n");
  set_race("shovel");
  set_gender("male");
  set_level(4);
  set_wc(8);
  set_ac(4);
  set_hp(60);
  set_ep(1000);
  add_money(0);
  set_aggressive(0);
set_dead_ob(this_object());
  set_al(200);
  load_chat("Shovel says: here comes more sand.\n");
  set_chat_chance(10);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/sand.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "A grain of sand falls off Shovel as he dies.\n");
return 0; }
