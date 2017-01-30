#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIW+"Zircon "+NORM+"Gargoyle");
set_alias("zircon");
set_race( "spirit");
set_long(
  "  The gargoyle stands firmly before you.  His large muscular body tensed,\n"+
  "ready to jump into battle.  The gargoyle is ready to protect his cursed\n"+
  "home.  Zircon was born and bred to fight strong and hard and die for his\n"+
  "cause.  His wings arched back behind his back, he gracefully waits for\n"+
  "any intruder to begin a fight with him.  He looks deadly.\n\n");
set_level(15+random(2));
set_ac(10+random(4));
set_wc(24+random(3));
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Zircon paces back and forth.\n");
  load_chat("Zircon says: Who goes there??\n");
set_a_chat_chance(10);
  load_a_chat("You strain to see Zircon and can't locate him.\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "\nZircon lowers his head and charges!\n");
set_spell_mess2(
  "\nZircon blitzes towards you, hitting you with a solid blow!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/zircon.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tZircon bursts into tiny pieces!\n\n");
return 0; }
