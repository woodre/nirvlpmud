#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("hot teacher");
  set_race("human");
  set_alias("teacher");
  set_short("Hot Teacher");
  set_long("\
The teacher is fresh out of college. She is a great looking woman\n\
and every male student wants to be in her class. She is a perfect\n\
36 28 36.\n");
  set_level(16);
  set_hp(250);
  set_wc(23);
  set_al(300);
  set_chat_chance(2);
  load_chat(query_name()+" asks, \"What can I do for you today?\"\n");
  load_chat("The teacher says, I am gonna make you earn that A!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(400)+150);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/chest_01.c");
  command("wear chest", this_object());
  armor=clone_object("/players/angel/area/school/obj/panties_01.c");
  move_object(armor, this_object());
  command("wear underwear", this_object());
  set_ac(13);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,20,"other|fire");
}  
