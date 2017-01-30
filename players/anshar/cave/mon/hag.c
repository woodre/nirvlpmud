#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
#include "/players/anshar/closed/mydef.h"

inherit "obj/monster.c";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("hag");
  set_alias("");
  set_race("");
  set_short("");
  set_long();
  set_level(20);
  set_hp(500);
  set_al(0);
  set_wc(30);
  set_ac(17);
  set_aggressive(0);
  set_chat_chance(9);
  load_chat("\n");
  load_chat("\n");
  load_chat("\n");
  set_a_chat_chance(10);
  load_a_chat("\n");
  load_a_chat("\n");
  load_a_chat("\n");
  gold = clone_object("obj/money");
  gold->set_money(4000 +random(1000));
  move_object(gold,this_object());
}
