#include "/players/linus/def.h"
inherit "/players/vertebraker/closed/std/monster.c";
id(str) { return str=="tigger" || str=="tiger" || str=="Linus_owns_this_tigger"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 msgout="says 'T-T-F-N, Ta Ta For Now!', and bounces";
 msgin="bounces in";
set_short("Tigger");
set_name("Tigger");
set_long(
 "                   T - I - Double Guh - er\n"+
 "A very bouncy animal, Tigger's top is made of rubber, and his bottom\n"+
 "is made of springs.  Tigger rarely sits still for very long, and loves\n"+
 "to have fun.  The most wonderful thing about being a tigger is that\n"+
 "he's the only one!\n");
set_aggressive(0);
set_race("tiger");
set_level(50);
set_wc(15);
set_ac(25);
set_al(1000);
set_wander(30, 0, ({"southwest"}));
set_chat_chance(10);
 load_chat("Tigger says: Hoo hoo hoo hewooo!\n");
 load_chat("Tigger bounces around...\n");
 load_chat("Tigger says: Heya buddy boy!\n");
set_a_chat_chance(10);
 load_a_chat("Tigger says: That's Re-dikorus!\n");
set_chance(5);
 set_spell_dam(25+random(50));
 set_spell_mess1("Tigger\n"+YEL+"     P O U N C E S\n"+NORM+
"                 on his attacker, knocking them to the ground!\n");
 set_spell_mess2("Tigger\n"+YEL+"     P O U N C E S\n"+NORM+
"                 on you, knocking you to the ground!\n");
set_dead_ob(TO);
}
monster_died() {
 tell_room(environment(TO),"With a final bounce, a large spring is torn from Tigger's body.\n");
 MO(CO("/players/linus/Newbie/obj/t_spring.c"),TO);
 return 1;
}
