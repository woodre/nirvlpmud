#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("pestilence");
   set_alias("man");
   set_alt_name("demon");
   set_race("undead");
   set_short("Pestilence, the horseman");
set_long("A dark man robed in yellow silk, figured with red and\n"+
"having a yellow silken mask, his eyes peering through had a\n"+
"darkness in them that would burn a soul.  His hands were\n"+
"monstrous and clawlike.  He is the dark high priest, legended\n"+
"never to have been described.\n");
   set_gender("male");
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
