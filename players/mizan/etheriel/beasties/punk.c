inherit "obj/monster";
#include "/players/mizan/closed/HighLevelGuard.c"

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("punk");
   set_race("humanoid");
   set_alias("dork");
   set_short("A punk");
   set_long("This guy looks like a punk, he smells like a punk, he talks like a punk..\n"+
	"Maybe he is a punk!\n");
   set_level(6);
   set_hp(175);
   set_al(-1000);
   set_wc(9);
   set_ac(4);
   set_chance(7);
   set_spell_dam(10);
   set_spell_mess1("Punk laughs at you!");
   set_spell_mess2("Punk taunts you and lunges!");
   set_chat_chance(7);
load_chat("Punk sneers at you.\n");
load_chat("Punk snickers.\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+150);
   move_object(gold,this_object());
}
