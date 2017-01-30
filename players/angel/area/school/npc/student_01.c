#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("1st grade Student");
  set_race("human");
  set_alias("student");
  set_short("A 1st grade student");
  set_long("\
This is a 1st grade student. He is the top of his class and has straight A's.\n");
  set_level(6);
  set_hp(90);
  set_wc(10);
  set_al(300); 
  set_chat_chance(4);
  load_chat(query_name()+" asks, \"Hello, what are you doing here?\"\n");
  load_chat("The student says, This is our classroom\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+25);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/underwear_01.c");
        move_object(armor, this_object());
        command("wear underwear", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/boots_02.c");
        move_object(armor, this_object());
        command("wear boots", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/pack_01.c");
        move_object(armor, this_object());
        command("wear shield", this_object());
        break;
    }
  set_ac(5);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     5,10,"other|fire");
}