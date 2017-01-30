#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("lillith");
   set_alias("goddess");
   set_alt_name("demon");
   set_race("undead");
   set_short("Lillith, the evil goddess");
set_long("A sexually aggressive, independent and strong-willed goddess.\n"+
"Her broken wings are bound in red, and she has the feet of a\n"+
"predatory bird.  Lillith was created at the same time as Adam,\n"+
"and was suppose to be his mate.  It was later discovered that\n"+
"she did not possess subservience later found in Eve.  She is\n"+
"ascribed the habit of spiriting off babies at night.\n");
   set_gender("female");
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
