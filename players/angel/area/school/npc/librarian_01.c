#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("school librarian");
  set_race("human");
  set_alias("librarian");
  set_short("School Librarian");
  set_long("\
The librarian appears to be in her mid 30's. She has a way with students!\n");
  set_level(13);
  set_hp(195);
  set_wc(17);
  set_al(300);
  set_chat_chance(3);
  load_chat(query_name()+" asks, \"Have you read a book today?\"\n");
  load_chat("The Librarian says, Come into the Library.\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+50);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/bracelet_01.c");
  move_object(armor, this_object());
  command("wear bracelet", this_object());
  set_ac(10);
  add_spell("fireball","#MN# throws a large $HR$book$N$ at you.\n",
                     "#MN# throws a large $HR$book$N$ at #TN#.\n",
                     10,20,"other|fire");
}
