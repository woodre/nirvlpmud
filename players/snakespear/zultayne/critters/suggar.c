#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIM+"Sugilite "+NORM+"Gargoyle");
set_alias("sugilite");
set_race( "spirit");
set_long(
  "  A gargoyle of very large proportions.  His imense size slows his agility\n"+
  "and speed.  However, his huge body can fight rather well.  Sugilite has\n"+
  "short, barely noticeable horns.  Wings open partially shows his readiness\n"+
  "for battle.  He is looking very strong.\n\n");
set_level(15+random(2));
set_ac(10+random(4));
set_wc(24+random(3));
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Sugilite stares down at you intently.\n");
  load_chat("Sugilite says: You've entered my home... now perish!\n");
set_a_chat_chance(10);
  load_a_chat("Sugilite massacres you to small fragments.\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "\nSugilite concentrates intently.\n");
set_spell_mess2(
  "\nSugilite massacres you to small fragments.\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/sugilite.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tSugilite bursts into tiny pieces!\n\n");
return 0; }
