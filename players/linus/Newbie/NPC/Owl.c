#include "/players/linus/def.h"
inherit "/obj/monster.c";
id(str) { return str=="owl"; }
 reset(arg)  {
   ::reset(arg);
   if(arg) return;
 set_name("Owl");
 set_short("Owl");
 set_long(
 "Owl is large, with a wingspan of about forty-two inches.  He is one of\n"+
 "the smarter residents of the hundred acre wood.  Owl loves to tell\n"+
 "stories, and has been known to go on for hours telling them.  Owl is\n"+
 "dark brown in color, with a light tan belly.\n");
 set_race("bird");
 set_level(8);
 set_ac(7);
 set_hp(100+random(51));
 set_wc(12);
 set_al(1000);
 set_chat_chance(5);
   load_chat("Owl says: what can I do for you?\n");
   load_chat("Owl rambles on with a story about something or other...\n");
 set_a_chat_chance(10);
   load_a_chat("Owl says: why do you attack me?\n");
   load_a_chat("Owl tries running back into his house, but has locked himself out.\n");
 set_dead_ob(TO);
 }
 monster_died() {
   tell_room(environment(TO),"As owl falls to the ground, some feathers land beside him.\n");
     MO(CO("/players/linus/Newbie/obj/owl_feathers.c"), environment(TO));
 return 1;
 }
