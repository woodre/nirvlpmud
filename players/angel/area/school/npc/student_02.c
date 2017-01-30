#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("2nd grade student");
  set_race("human");
  set_alias("student");
  set_short("A 2nd grade student");
  set_long("\
This is a 2nd grade student. She is very active.\n");
  set_level(7);
  set_hp(105);
  set_wc(11);
  set_al(300);
  set_chat_chance(5);
  load_chat(query_name()+" asks, \"May I to go to the playground?\"\n");
  load_chat("The student says, This is our classroom!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(100)+15);
  move_object(gold, this_object());
      switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/panties_01.c");
        move_object(armor, this_object());
        command("wear underwear", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/sweater_01.c");
        move_object(armor, this_object());
        command("wear chest", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/charm_01.c");
        move_object(armor, this_object());
        command("wear bracelet", this_object());
        break;
    }
  set_ac(6);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     5,10,"other|fire");
}