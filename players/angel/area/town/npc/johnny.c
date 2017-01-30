#include <ansi.h>

#include "/players/angel/area/include/mob_utility.c"


reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("johnny");
  set_wander(1);
  set_wander_interval(10);
  set_wander_realm("/players/angel");
  set_race("human");
  set_alias("kid");
  set_short("Johnny the kid");
  set_long("\
Johnny is an 10 year old child. He is always running away from home.\n");
  set_level(8);
  set_hp(135);
  set_wc(12);
  set_ac(7);
  set_al(0);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(6);
  set_wander_realm("/players/angel/area/town/room/");
  set_chat_chance(10);
  load_chat(query_name()+" asks, \"Do you have some food or money I can have?\"\n");
  load_chat("The kids says, man I am starving!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(300)+50);
  move_object(gold, this_object());
  add_spell("Brick","#MN# throws a large $HR$BRICK$N$ at you.\n",
                     "#MN# throws a large $HR$BRICK$N$ at #TN#.\n",
                     5,10,"physical");
}
