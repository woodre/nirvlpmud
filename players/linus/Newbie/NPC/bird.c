#include "/players/linus/def.h"
inherit "/obj/monster.c";
 id(str) { return str=="bird" || str=="blue bird"; }
  reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("A small"+HIB+" blue bird"+NORM);
 set_long("A small"+HIB+" blue bird"+NORM+".  It chirps happily as it hops around\n"+
       "in the meadow looking for bugs to eat.\n");
 set_race("bird");
 set_level(2);
 set_hp(30);
 set_ac(3);
 set_wc(6);
 set_a_chat_chance(10);
 load_a_chat("The bird flaps it's wings but it cannot fly away.\n");
 set_dead_ob(TO);
}
monster_died() {
 tell_room(environment(TO),"As the bird dies, a feather falls to the ground.\n");
 MO(CO("/players/linus/Newbie/obj/feather.c"),environment(TO));
 return 1;
}
