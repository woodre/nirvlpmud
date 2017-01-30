#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("student");
  set_race("human");
  set_alias("student");
  set_short("Student");
  set_long("\
These gym students are very excited to be in class. They just\n\
can't wait to play kickball\n");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_al(300);
  set_chat_chance(3);
  load_chat(query_name()+" asks, \"What are we doing today?\"\n");
  load_chat("The student says, I want to play kickball!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(50)+5);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/shorts_01.c");
        move_object(armor, this_object());
        command("wear pants", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/shirt_01.c");
        move_object(armor, this_object());
        command("wear shirt", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/tanktop_01.c");
        move_object(armor, this_object());
        command("wear chest", this_object());
        break;
    }
  set_ac(5);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}