#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("4th grade Student");
  set_race("human");
  set_alias("student");
  set_short("A 4th grade student");
  set_long("\
This is a 4th grade student. She appears to be creating something\n");
  set_level(8);
  set_hp(120);
  set_wc(12);
  set_al(300);
  set_chat_chance(3);
  load_chat(query_name()+" says, \"Hello, this is my science project!\"\n");
  load_chat("The student says, Only 4th and 5th grade get to enter!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(200)+5);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/tanktop_01.c");
        move_object(armor, this_object());
        command("wear chest", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/charm_01.c");
        move_object(armor, this_object());
        command("wear bracelet", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/shorts_01.c");
        move_object(armor, this_object());
        command("wear pants", this_object());
        break;
    }
  set_ac(8);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}