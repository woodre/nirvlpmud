#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("sick student");
  set_race("human");
  set_alias("student");
  set_short("Sick Student");
  set_long("\
This student is very sick. He is holding a trash can.\n");
  set_level(5);
  set_hp(90);
  set_wc(9);
  set_ac(4);
  set_chat_chance(5);
  load_chat(query_name()+" asks, \"Can I get a clean trash can?\"\n");
  load_chat("The sick boy says, I want my mommy!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(250)+5);
  move_object(gold, this_object());
}
