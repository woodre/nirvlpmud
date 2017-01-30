#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  if(arg) return;
  ::reset(arg);
  set_name("bradley");
  set_race("human");
  set_alias("kid");
  set_alt_name("terror");
  set_short("Bradley the Terror");
  set_long("\Bradley is an 10 year old child. He is always running away from home.\n");
  set_level(8);
  set_hp(135);
  set_wc(12);
  set_ac(7);
  set_al(-200);
  set_aggressive(2);
  set_heart_beat(1);
  set_wander(1);
  set_wander_interval(6);
  set_wander_realm("/players/angel/area/town/room/");
  set_chat_chance(8);
  load_chat(query_name()+" asks, \" Who the HELL do you think you are?\"\n");
  load_chat("The kids says,  Yes! It is I, Bradley, the Magnificent!\n");
  load_chat("The kids says, You guys are DEFINITELY on my shit list!\n");
  weapon=clone_object("/players/angel/area/town/obj/knife.c");
  move_object(weapon,this_object());
  init_command("wield knife");
  gold=clone_object("obj/money");
  gold->set_money(random(200)+50);
  move_object(gold, this_object());
  call_out("random_move",10);
  add_spell("lazer","#MN# shoots his Evil Emporer Zurg $HR$L A Z E R$N$ gun at you.\n",
                     "#MN# shoots his Evil Emporer Zurg $HR$L A Z E R$N$ gun at #TN#.\n",
                     10,10,"other|lazer");
}
