#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("3rd grade Student");
  set_race("human");
  set_alias("student");
  set_short("A 3rd grade student");
  set_long("\
This is a 3rd grade student. He won the school spelling bee.\n");
  set_level(7);
  set_hp(105);
  set_wc(12);
  set_al(300);
  set_chat_chance(4);
  load_chat(query_name()+" asks, \"Dextromethorphan, D e x t r o m e t h o r p h a n!\"\n");
  load_chat("The student exclaims, That was the winning word!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(100)+5);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/jeans_01.c");
        move_object(armor, this_object());
        command("wear pants", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/belt_01.c");
        move_object(armor, this_object());
        command("wear belt", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/bracelet_01.c");
        move_object(armor, this_object());
        command("wear bracelet", this_object());
        break;
    }
  set_ac(7);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}