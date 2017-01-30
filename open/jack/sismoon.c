#include "/players/puppy/define.h"

inherit "/obj/monster.c";

reset(arg) {
object gold;
  ::reset(arg);
  if(arg) return;
  set_name("sister");
  set_alt_name("it");
  set_alias("monster");
  set_short("Sister Moon");
  set_long(This beauty is bathed in a pale light.  She is wearing an almost transparent robe that does not completely hide her majestic wings.\n");
  set_gender("female");
  set_race("monster");
  set_level(10);
  set_wc(15);
  set_ac(8);
  set_hp(150);
  set_al(1);
set_aggressive(0);
  add_money(450);  

set_chat_chance(10);
load_chat("Isn't the moon beautiful tonite?\n");

set_a_chat_chance(10);
load_a_chat("Didn't your mother ever tell you it is wrong to hit a girl?\n");
  set_chance(10);
set_spell_dam(100);
set_spell_mess1( 
"Sister Moon calls on the powers of the Moon to aid her.\n");

set_spell_mess2(
"Sister Moon cries out, and you feel weaker.\n");

gold = clone_object("obj/money");
gold->set_money(450);
move_object(gold,this_object());
}
