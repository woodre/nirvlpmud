#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("5th grade Student");
  set_race("human");
  set_alias("student");
  set_short("A 5th grade student");
  set_long("\
This is a 5th grade student. He is infatuated with his teacher.\n");
  set_level(9);
  set_hp(135);
  set_wc(13);
  set_al(300);
  set_chat_chance(5);
  load_chat(query_name()+" asks, \"Hello, what do you think of my teacher?\"\n");
  load_chat("The student exclaims, I love my teacher!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(200)+5);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/chain_01.c");
        move_object(armor, this_object());
        command("wear necklace", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/shirt_01.c");
        move_object(armor, this_object());
        command("wear chest", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/bracelet_01.c");
        move_object(armor, this_object());
        command("wear bracelet", this_object());
        break;
    }
  set_ac(7);
  add_spell("fireball","#MN# throws a pile of$HR$volcano lava$N$ at you.\n",
                     "#MN# throws a pile of $HR$volcano lava$N$ at #TN#.\n",
                     20,20,"other|fire");
}