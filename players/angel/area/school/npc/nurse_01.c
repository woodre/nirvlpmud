#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("school nurse");
  set_race("human");
  set_alias("nurse");
  set_short("School Nurse");
  set_long("\
She looks to be in her 50's but she is in very good shape\n");
  set_level(13);
  set_hp(195);
  set_wc(17);
  set_chat_chance(2);
  load_chat(query_name()+" asks, \"Hello, what can I do for you today?\"\n");
  load_chat("The nurse ask, How are you feeling?\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+25);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/gloves_01.c");
  move_object(armor, this_object());
  command("wear gloves", this_object());
  set_ac(10);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}