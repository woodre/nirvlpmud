#include "/players/eurale/closed/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("hamster");
set_alias("giant");
set_race("creature");
set_short("a giant space hamster");
set_long(
  "This giant space hamster is exactly what it sounds like - cute\n"+
  "but brown-bear-sized with thick fur.  They come in a variety of\n"+
  "colors, but are usually golden brown with white underbellies.\n"+
  "This one is well muscled but appears fat.  Many giant space\n"+
  "hamsters have been known to store up to 200 pounds of food in\n"+
  "its cheeks.\n");

set_level(19);
  set_hp(475);
  set_al(0);
  set_wc(28);
  set_ac(14);
  set_aggressive(0);

set_chat_chance(15);
  load_chat("The hamster scurries about the room.\n");
set_a_chat_chance(15);
  load_a_chat("The hamster SQUEEKS in pain...\n");

gold = clone_object("obj/money");
gold->set_money(1800 + random(400));
move_object(gold,this_object());
}
