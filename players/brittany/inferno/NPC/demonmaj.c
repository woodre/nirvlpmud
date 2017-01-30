#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("demon");
   set_alias("beast");
   set_alt_name("major");
   set_race("creature");
   set_short("Demon major");
set_long("A dark elegant creature, that is the physical essence of corruption.\n"+
"Almost alien, it's frame is layer upon layer of fleshy decay.  It's\n"+
"body is winged, scaled, and dressed in every form of organic clothing\n"+
"imaginable.  The robe is made of pressed brains, crenelated like\n"+
"twisted spaghetti.  The tunic is armored in wildly deformed bone inlaid\n"+
"with blinking eyes.  The pants are cut from hundreds of scalps and\n"+
"slicked with sweat.\n");
   set_gender("undead");
   set_level(20);
   set_hp(500);
   set_wc(30);
   set_ac(17);
   set_al(-50);
   set_aggressive(0);
   set_dead_ob(this_object());
   
   set_chat_chance(9);
load_chat("The dark figure turns and looks into your direction.\n");
   
   set_chance(10);
   set_spell_dam(30);
   
   gold = clone_object("obj/money");
   gold->set_money(1000);
   move_object(gold,this_object());
}

monster_died() {
move_object(clone_object("/players/brittany/inferno/OBJ/eye.c"),
      environment(this_object()));
   tell_room(environment(this_object()),
     "The creature dies, an eye falls on the ground.\n");
   return 0; }
