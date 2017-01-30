#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIR+"Jasper "+NORM+"Gargoyle");
set_alias("jasper");
set_race( "spirit");
set_long(
  "  This is a average sized gargoyle with claws at the tip of each wing.\n"+
  "His body is a gleaming red color and he looks very solid.  His feet smack\n"+
  "the ground with hard pounds each step he takes towards you. Slowly, his\n"+
  "arms raise and he prepares to take you down.\n");
set_level(15+random(2));
set_ac(10+random(4));
set_wc(24+random(3));
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Jasper clampers towards you.\n");
  load_chat("Jasper says: I miss our meetings...\n");
set_a_chat_chance(10);
  load_a_chat("Jasper runs around you in circles.\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "Jasper inhales deeply and lets out a ferocious roar!\n");
set_spell_mess2(
  "Jasper roars and kicks you!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/jasper.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tJasper * E X P L O D E S * all over the room!\n\n");
return 0; }
