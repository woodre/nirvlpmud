#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("school teacher");
  set_race("human");
  set_alias("teacher");
  set_short("School Teacher");
  set_long("\
This is an average school teacher. She is in her mid 40's.\n\
She enjoys working with little children\n");
  set_level(13);
  set_hp(195);
  set_wc(17);
  set_al (300);
  set_chat_chance(2);
  load_chat(query_name()+" asks, \"How are you today?\"\n");
  load_chat("The teacher says, Good morning class!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+25);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/charm_01.c");
  move_object(armor, this_object());
  command("wear bracelet", this_object());
  set_ac(10);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}