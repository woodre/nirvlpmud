#include "/players/pestilence/ansi.h"
inherit "/obj/monster.c";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("pail"); 
  set_alias("pail");
  set_short("Pail");
  set_long("This is Pail.  Pail is red with a yellow handle.  There is\n"+
           "a face on the front of the pail from which he speaks from.\n");
  set_race("pail");
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
  load_chat("Pail says: i think i can carry some more sand.\n");
  set_chat_chance(10);
}
monster_died() {
  move_object(clone_object("/players/pestilence/blue/obj/sand.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
        "Some sand falls out of Pail as he dies.\n");
return 0; }
