#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("library student");
  set_race("human");
  set_alias("student");
  set_short("A student quietly reading");
  set_long("\
A student quietly reading. He is intrigued by Stephen King!\n");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_al(300);
  set_chat_chance(3);
  load_chat(query_name()+" asks, \"Have you read any Stephen King's book?\"\n");
  load_chat("The student says, Shh, you have to be quiet!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(50)+5);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/book_01.c");
  move_object(armor, this_object());
  command("wear book", this_object());
  set_ac(5);
}