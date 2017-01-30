#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("cloud");
   set_race("undead");
   set_short("A Black Cloud");
set_long("A black cloud about 150 million kilometers in diameter.  At its\n"+
"center is a complex neurological system made up of a piece of rock\n"+
"that has layers of molecular chains.\n");
   set_level(20);
   set_hp(500);
   set_wc(30);
   set_ac(17);
   set_al(-50);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(9);
load_chat("The black cloud emits an explosive jet of gasses, like a rocket\n"+
"into the sky.\n");
   
   set_chance(10);
   set_spell_dam(30);
   
set_spell_mess1(
"The cloud emits a poisonous gas in the air.\n");
set_spell_mess2(
"The guard emit sharp quills from its tail, cutting you deeply.\n");
}

monster_died() {
move_object(clone_object("/players/brittany/kadath/crucifix.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
      "msg \n");
   return 0; }
