#include <ansi.h>
inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Principal Ray");
  set_alt_name("ray");
  set_race("human");
  set_alias("principal");
  set_short("Principal Ray");
  set_long("\
This the school principal. He is over 6 feet tall with a slender\n\
build. He looks like he is Italian.\n");
  set_level(18);
  set_hp(500);
  set_wc(27);
  set_al(-200);
  set_chat_chance(4);
  load_chat(query_name()+" asks, \"Hello, how may I help you today?\"\n");
  load_chat("Mr. Ray says, You can't seem to stay out of my office!\n");
  gold=clone_object("obj/money");
  gold->set_money(random(1000)+500);
  move_object(gold, this_object());
  armor=clone_object("/players/angel/area/school/obj/mason_ring_01.c");
  move_object(armor, this_object());
  command("wear ring", this_object());
  set_ac(17);
  add_spell("fireball","#MN# throws a large $HR$fireball$N$ at you.\n",
                     "#MN# throws a large $HR$fireball$N$ at #TN#.\n",
                     30,50,"other|fire");
}
