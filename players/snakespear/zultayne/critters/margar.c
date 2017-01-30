#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short(HIW+"Ma"+GRY+"rb"+HIW+"le "+NORM+"Gargoyle");
set_alias("marble");
set_race( "spirit");
set_long(
  "  A beautiful gargoyle of small proportions.  Small horns extend from his\n"+
  "head.  The horns are quite crooked and chiseled.  Tiny wings lay close to\n"+
  "his back.  The wings look small, but they must be strong enough to carry\n"+
  "the weight of Marble.\n");
set_level(15+random(2));
set_ac(10+random(4));
set_wc(24+random(3));
set_hp(350+random(50));
set_al(-100+random(100));
set_aggressive(0+random(1));
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Marble stares at the statue with tears in his eyes.\n");
  load_chat("Marble sighs.\n");
set_a_chat_chance(10);
  load_a_chat("Tears run down the face of the gargoyle.\n");  
set_chance(10);
set_spell_dam(15+random(5));

set_spell_mess1(
  "\nMarble opens his wings and erupts in fury!\n");
set_spell_mess2(
  "\nMarble throws himself into you!\n");

gold = clone_object("obj/money");
gold->set_money(575);
move_object(gold,this_object());
 }

monster_died() {
  move_object(clone_object("/players/snakespear/zultayne/treasure/marble.c"),
      environment(this_object()));
  tell_room(environment(this_object()),
      "\n\n\t\tThe gargoyle lets out a final sigh...\n\n");
return 0; }
