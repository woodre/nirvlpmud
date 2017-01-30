#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIC+"Ama"+HIG+"zoni"+HIC+"te "+NORM+"Gargoyle");
set_alias("amazonite");
set_race( "spirit");
set_long(
  "  A weakly looking gargoyle.  His body is frail and weak.  He\n"+
  "looks like he is trying to locate some sort of sustance.  One\n"+
  "can only hope that this gargoyle isn't a carnivore.  But would\n"+
  "one chance the food deprived?\n\n");
set_level(15+random(2));
set_ac(10+random(4));
set_wc(24+random(3));
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Amazonite searches for something to eat.\n");
  load_chat("The gargoyle gazes at you sadly.\n");
set_a_chat_chance(10);
  load_a_chat("Amazonite drools.\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "Amazonite attacks with a vengence!\n");
set_spell_mess2(
  "Amazonite takes a bite out of your chest!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/amazonit.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tAmazonite -= S H A T T E R S =- into nothing!\n\n");
return 0; }
