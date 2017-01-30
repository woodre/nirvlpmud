#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Asst Principal McArthur");
  set_alt_name("mcarthur");
  set_race("human");
  set_alias("principal");
  set_short("Assistant Principal McArthur");
  set_long("\
This is the assistant principal. She appears to be of average size\n\
with a slender body. She has many duties that keep her very active.\n\
Principal McArthur is a force to be reckoned with, beware!\n");
  set_level(18);
  set_hp(500);
  set_wc(32);
  set_al(0);
  set_chat_chance(2);
  load_chat(query_name()+" asks, \"Hello, how may I help you today?\"\n");
  load_chat("Ms. McArthur says, You can't seem to stay out of my office!\n");
  gold=clone_object("obj/money");
  gold->set_money(1000);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/flow_scarf_01.c");
  move_object(armor, this_object());
  command("wear scarf", this_object());
  set_ac(20);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     30,50,"other|fire");
}