#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("gym teacher");
  set_race("human");
  set_alias("teacher");
  set_short("Gym Teacher");
  set_long("\
He is well built. He is in his early 20's and has six pack abs.\n");
  set_level(15);
  set_hp(250);
  set_wc(20);
  set_al(300);
  set_chat_chance(2);
  load_chat(query_name()+" asks, \"You want to run another lap?\"\n");
  load_chat("The gym teacher says, give me 20 pushup!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(700)+50);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/boots_01.c");
  move_object(armor, this_object());
  command("wear boots", this_object());
  set_ac(12);
  add_spell("fireball","#MN# throws Red $HR$dodge balls$N$ at you.\n",
                     "#MN# throws Red $HR$dodge balls$N$ at #TN#.\n",
                     10,20,"other|fire");
}