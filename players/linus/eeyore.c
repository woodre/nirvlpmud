#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="eeyore" || str=="donkey"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
set_name("Eeyore");
set_short("Eeyore");
set_long(
 "Eeyore moves slowly about the meadow.  He is an old grey donkey with\n"+
 "long, droopy ears.  He is stuffed with sawdust, and is quite sad\n"+
 "because his tail always falls off.  His friends have tried to help\n"+
 "by using a tack to hold it in place.\n");
set_race("donkey");
set_level(20);
set_hp(500+random(51));
set_ac(17);
set_wc(25);
set_al(100);
add_money(3000+random(1000));
set_chat_chance(10);
 load_chat("Eeyore sighs...\n");
 load_chat("Eeyore says, It's a lovely day...isn't it.\n");
 load_chat("Eeyore takes a bite of grass.\n");
set_a_chat_chance(10);
 load_a_chat("Eeyore says: Might as well put me out of my misery...\n");
 load_a_chat("Eeyore's tail starts coming loose...\n");
set_dead_ob(TO);
}
monster_died() {
 tell_room(environment(TO),"As Eeyore dies, his tail falls to the ground.\n");
 MO(CO("/players/linus/Newbie/obj/e_tail.c"), environment(TO));
 return 1;
}
