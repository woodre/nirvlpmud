#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("playground student");
  set_race("human");
  set_alias("student");
  set_short("Playground Student");
  set_long("\
This is an average student on the playground.  He is using up all of\n\
his energy .\n");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_al(300);
  set_chat_chance(4);
  load_chat(query_name()+" asks, \You want to join the game?\"\n");
  load_chat("The student says, It's lots of fun!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(50)+25);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/shirt_01.c");
        move_object(armor, this_object());
        command("wear chest", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/bbgloves_01.c");
        move_object(armor, this_object());
        command("wear glove", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/guards_01.c");
        move_object(armor, this_object());
        command("wear guards", this_object());
        break;
    }
  set_ac(5);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}