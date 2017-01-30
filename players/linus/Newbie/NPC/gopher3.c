#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="female_gopher" || str=="gopher"; }
 reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("gopher");
set_short("A female gopher");
set_long("A small female gopher that lives in Rabbit's garden.  She glances\n"+
 "up at you and chatters noisily.\n");
set_race("rodent");
set_level(5);
set_wc(7);
set_ac(4);
set_hp(65);
set_dead_ob(TO);
set_a_chat_chance(10);
load_a_chat("The gopher bites you HARD!\n");
}
monster_died() {
 tell_room(environment(TO),"The gopher's front teeth are knocked out as his head hits the ground.\n");
 MO(CO("/players/linus/Newbie/obj/g_teeth.c"),TO);
 return 1;
}
