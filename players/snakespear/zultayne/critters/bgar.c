#include "/players/snakespear/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg) {
 object gold;
   ::reset(arg);
   if(arg) return;


set_name("gargoyle");
set_short("A baby Gargoyle");
set_alias("baby");
set_race( "spirit");
set_long(
  "  A very young gargoyle.  He looks like he is about 100 years old.  His\n"+
  "small wings are frail and torn from trying to learn how to fly.  He's\n"+
  "never got the chance to go through the training that those before him\n"+
  "did.  Will he ever get a chance to learn?\n");
set_level(10+random(2));
set_ac(9);
set_wc(15);
set_hp(200+random(50));
set_al(500+random(-1000));
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("The baby whines loudly.\n");
  load_chat("The baby leaps in efforts of flying, but falls.\n");
set_a_chat_chance(10);
  load_a_chat("Baby cries louder and louder.\n");  
set_chance(10);
set_spell_dam(10+random(5));

set_spell_mess1(
  "The baby gets upset and vomits.\n");
set_spell_mess2(
  "Baby vomits all over you!\n");

gold = clone_object("obj/money");
gold->set_money(500);
move_object(gold,this_object());
 }

monster_died() {
  tell_room(environment(this_object()),
      "\n\nThe baby gargoyle falls to the ground limp with no life.\n\n");
return 0; }
