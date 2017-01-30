#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIG+"Malachite "+NORM+"Gargoyle");
set_alias("malachite");
set_race( "spirit");
set_long(
  "  This tall gargoyle has very small wings and his face looks like that\n"+
  "of a demon.  Long, crooked horns extend from his stone skull.  Muscles\n"+
  "bulge from his body and his coloring is green with different hues of\n"+
  "green streaking across his body.  He looks very angry.\n");
set_level(15+random(2));
set_ac(10);
set_wc(24);
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Malachite mutters unknown words.\n");
  load_chat("Heavy breathing comes from the gargoyle.\n");
set_a_chat_chance(10);
  load_a_chat("Malachite says: Nobody will find the statue!\n");  
set_chance(10);
set_spell_dam(20+random(5));

set_spell_mess1(
  "\nMalachite moves quickly, evading attacks!\n");
set_spell_mess2(
  "\nMalachite parrys your attack, then slams his fist through your chest!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/malachit.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tMalachite mutters: You'll never find.... \n\n");
return 0; }
