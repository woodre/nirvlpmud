#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("darven");
set_alt_name("bar_owner");
set_alias("owner");
set_race("human");
set_short("Darven the bartender");
set_long(
"   This is a thin, tall man. He runs the bar here in\n"+
"Terk'ula. He seems happy, yet weary of newcomers. His\n"+
"eyes watch the room carefully.\n");
set_level(4);
set_hp(60);
set_al(0);
set_wc(8);
set_ac(4);
set_aggressive(0);

set_chat_chance(5);
  load_chat("Darven says: Can I help ya?\n");
  load_chat("The bartender cleans the counter.\n");
  load_chat("The bartender serves some customers food.\n");
set_a_chat_chance(15);
  load_a_chat("Darven lashes out at you!\n");
  load_a_chat("The bartender throws a wild swing at you!\n");
gold = clone_object("obj/money");
gold->set_money(120);
move_object(gold,this_object());
}

