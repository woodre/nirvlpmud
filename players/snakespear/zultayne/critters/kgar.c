#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIY+"K"+HIW+"u"+HIY+"n"+HIW+"z"+HIY+"i"+HIW+"t"+HIY+"e "+NORM+"Gargoyle");
set_alias("kunzite");
set_race( "spirit");
set_long(
  "  A short squatty gargoyle that has a very ugly face.  His skin is very\n"+
  "shiney and looks very fragile.  Small horns protrude from his temples\n"+
  "both pointing upwards, however they seem very dull.  Prepared to battle,\n"+
  "he is ready to defend his home, no matter the size of the foe.\n");
set_level(15+random(2));
set_ac(10);
set_wc(24);
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Kunzite pauses and looks calm.\n");
  load_chat("You tremble as the mighty Kunzite looks into your eyes.\n");
set_a_chat_chance(10);
  load_a_chat("Kunzite lets out a gutteral moan.\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "Kunzite howls louldy!\n");
set_spell_mess2(
  "Kunzite howls loudly and punches you in the face!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/kunzite.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tThe Gargoyle shatters with your last swing ! ! \n\n");
return 0; }
