#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="christopher robin" || str=="boy" || str=="christopher" || str=="chris"; }
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("Christopher Robin");
 set_short("A small boy");
 set_long(
 "Christopher Robin is a small boy who likes spending time with his\n"+
 "friends from the hundred acre wood.  His light brown hair is uncombed,\n"+
 "and the wind makes it flop about his head in different directions.  He\n"+
 "is wearing a small dress shirt and blue shorts.  He has a small picnic\n"+
 "area set up in his front yard, where he is waiting for his friends to\n"+
 "arrive.\n");
 set_level(8);
 set_race("human");
 set_ac(7);
 set_wc(12);
 set_hp(110+random(21));
 add_money(300+random(101));
 set_chat_chance(10);
 load_chat("Where is that silly old bear?\n");
 load_chat("Christopher Robin arranges the blanket and picnic basket.\n");
 load_chat("Christopher Robin says: I am the master of the hundred acre wood!\n");
 set_a_chat_chance(10);
 load_a_chat("Christopher Robin says: I will defeat you!\n");
 load_a_chat("Christopher Robin says: Ouch! That hurt you big meanie!\n");
 set_chance(10);
 set_spell_dam(10);
 set_spell_mess1(
 "Christopher Robin kicks his attacker in the shin hard!\n");
 set_spell_mess2(
 "Christopher Robin kicks you in the shin hard!\n");
}
