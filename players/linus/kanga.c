#include "/players/linus/def.h"
inherit "/obj/monster.c";
object coins;
id(str) { return str=="kanga"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Kanga");
 set_short("Kanga");
 set_long(
 "With gentle eyes, Kanga looks at you and smiles.  She is a full grown\n"+
 "kangaroo with reddish-brown fur, a long tail, and long, pointed ears.\n"+
 "She has a pouch on her belly, and two powerful hind legs that she\n"+
 "stands on.  She is baking some cookies to bring to Christopher Robin's\n"+
 "house for a picnic.\n");
 set_race("kangaroo");
 set_level(20);
 set_ac(18);
 set_wc(30);
 set_hp(500);
 set_chat_chance(10);
 load_chat("Kanga checks on the cookies...\n");
 load_chat("Kanga says: Are you ready to go to the picnic, Roo?\n");
 set_a_chat_chance(10);
 load_a_chat("Kanga says: Why do you attack me?\n");
 load_a_chat("Kanga says: Help! Someone please help me!\n");
 set_chance(15);
 set_spell_dam(15+random(10));
 set_spell_mess1(
 "Kanga rears up on her tail and\n"+RED+
 "                           K I C K S\n"+NORM+
 "                                 her attacker across the room.\n");
 set_spell_mess2(
 "Kanga rears up on her tail and\n"+RED+
 "                           K I C K S\n"+NORM+
 "                                 you across the room.\n");
 set_dead_ob(TO);
}
monster_died() {
 tell_room(environment(TO),"As Kanga dies, some cookies fall out of her pouch.\n");
 MO(CO("/players/linus/Newbie/obj/cookies.c"), environment(TO));
 return 1;
}
