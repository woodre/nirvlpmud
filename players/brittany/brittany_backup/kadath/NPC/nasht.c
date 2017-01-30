#include "/players/brittany/ansi"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("nasht");
   set_alias("man");
   set_alt_name("priest");
   set_race("human");
   set_short("A Bearded Priest");
   set_long("A young bearded priest who performs invocations of\n"+
"dreams.  He is dressed in a black silk long robe,\n"+
"trimmed in red.  A gold crucifix dangles from his\n"+
"neck.  He mumbles some words that can not be\n"+
"understood.\n");
   set_gender("male");
   set_level(15);
   set_hp(225);
   set_wc(20);
   set_ac(12);
   set_al(0);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(4);
   load_chat("Priest says:  A journey into the unknown city would be the\n"+
      "death of souls.\n");
   load_chat("Priest says:  In our dreamland, the city might be reached.\n");
   load_chat("Priest says:  No man has ever reached Kadath.\n");
   load_chat("Priest says:  The Great Ones wish not to be harassed.\n");
   
   set_chance(15);
   set_spell_dam(30);

set_spell_mess1(
"The priest swings wildly at it's opponent.\n");
set_spell_mess2(
"The priest swings wildly at you.\n");
   
   gold = clone_object("obj/money");
   gold->set_money(500);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/OBJ/crucifix.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The priest blesses you, then dies.\n");
   return 0; }
