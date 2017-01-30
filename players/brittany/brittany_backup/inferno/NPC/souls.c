#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("souls");
   set_alias("beast");
   set_alt_name("major");
   set_race("creature");
   set_short("Demon minor");
set_long("They seemed as if they were just awakening.  Its movements are\n"+
"slow, jerky and cautious.  On its distorted body it stood about five feet\n"+
"tall, its right leg appeared normal, but its left leg was as thick around as\n"+
"a watermelon and ended into a toeless club.  It had one arm missing,\n"+
"and without any signs of genitalia it is hard to tell that it is female.\n"+
"Her headless head was of ossified crinkles, stretched on one side into a\n"+
"curling bony fin.  A red scabby sore showed where her bony chin scraped her\n"+
"shoulder.  A black orb was sunken into her chest.\n");
   set_gender("undead");
   set_level(20);
   set_hp(500);
   set_wc(30);
   set_ac(17);
   set_al(-50);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(9);
load_chat("The dark figure raises his clawlike paw and points\n"+
"to the circle inside the ringed altar.\n");
   
   set_chance(10);
   set_spell_dam(30);
   
   gold = clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/crucifix.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
      "msg \n");
   return 0; }
