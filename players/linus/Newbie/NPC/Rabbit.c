#include "/players/linus/def.h"
inherit "/obj/monster.c";
 object hoe;
 reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("Rabbit");
 set_short("Rabbit");
 set_long(
 "One of the smarter residents of the hundred acre wood, Rabbit is pushy\n"+
 "and decisive.  He is yellow in color, and has long ears, one of which\n"+
 "flops down ever so slightly.  Rabbit takes great pride in his garden\n"+
 "and is quite upset because gophers are going to eat all the vegetables\n"+
 "he's planted for Christopher Robin's picnic.\n");
 set_race("rabbit");
 set_level(8);
 set_wc(0);
 set_ac(7);
 set_hp(110+random(31));
 set_al(1000);
 hoe=CO("/players/linus/Newbie/obj/hoe.c");
           MO(hoe,TO);
           command("wield hoe",TO);
 set_chat_chance(10);
 load_chat("Rabbit says: Gophers are always in my garden!\n");
 load_chat("Rabbit looks at his garden...\n");
 load_chat("Rabbit says: It's a lovely garden...don't you agree?\n");
 set_chance(10);
 set_spell_dam(10);
 set_spell_mess1(
 "Rabbit swings his hoe and it comes crashing down on his attackers head!\n");
 set_spell_mess2(
 "Rabbit swings his hoe and it comes crashing down on your head!\n");
 }
