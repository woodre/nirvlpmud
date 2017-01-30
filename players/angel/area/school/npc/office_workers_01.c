#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("office worker");
  set_race("human");
  set_alias("worker");
  set_short("Office Worker");
  set_long("\
She is in her 50's with long gray hair. She is wearing a nice\n"+
"piece of jewelry.\n");
  set_level(13);
  set_hp(135);
  set_wc(17);
  set_al(300);
  set_chat_chance(3);
  load_chat(query_name()+" asks, \"Would you sign in first, please?\"\n");
  load_chat("The office worker says, I will have to give you a name tag!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+50);
  move_object(gold, this_object());
    switch(random(3))
    {
      case 0:
        armor=clone_object("/players/angel/area/school/obj/necklace_01.c");
        move_object(armor, this_object());
        command("wear necklace", this_object());
        break;
      case 1:
        armor=clone_object("/players/angel/area/school/obj/earing_01.c");
        move_object(armor, this_object());
        command("wear earing", this_object());
        break;
      case 2:
        armor=clone_object("/players/angel/area/school/obj/bracelet_01.c");
        move_object(armor, this_object());
        command("wear bracelet", this_object());
        break;
    }
  set_ac(10);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     10,10,"other|fire");
}