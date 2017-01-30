#include "/players/feldegast/defines.h"
inherit "obj/monster";
reset(arg){
   object gold,ring,cloak;
   ::reset(arg);
   if(arg) return;
   set_name("melko");
   set_race("god");
   set_alias("melko");
   set_short(BOLD+"Melko"+NORM+", the "+BOLD+BLK+"God of Evil"+NORM);
   set_long(
"This is the almighty Melko, Lord of Darkness and Ultimate God of Evil.  His\n"+
"face, under a little pair of curved horns, doesn't show any feeling.  He\n"+
"wears a long purple cloak that hides his true appearance from your site.\n"+
"You can only see he's damned tall and that He doesn't stand on the floor but\n"+
"simple levitates a few feet above it.\n");
   set_level(21);
   set_hp(1200);
   set_al(-5000);
   set_wc(45);
   set_ac(20);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Melko says: Mortal one, do you dare to challenge me?\n");
   load_chat("Melko looks at you from behind His unexpressive face.\n");
   load_chat("Melko says: You have been brave and lucky to reach me, but surely\n"+
             "            you don't dare go any further?\n");
   load_chat("Melko laughs and you feel your guts twist into knots.\n");
   set_chance(5);
   set_spell_dam(random(10)+20);
   set_spell_mess1("Melko smashes you to the ground with the power of His mind.");
   set_spell_mess2("Melko summons thunder, points His finger at you, and sends it flying at you!");
   gold=clone_object("obj/money");
   gold->set_money(4500 + random(50));
   move_object(gold,this_object());
   ring=clone_object("players/trix/castle/quest/monst/ring");
   move_object(ring,this_object());
   cloak=clone_object("players/trix/castle/quest/monst/mcloak");
   move_object(cloak,this_object());
}

