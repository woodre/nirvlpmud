#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("entered apprentice");
  set_alt_name("mason");
  set_race("Mason");
  set_alias("apprentice");
  set_short("Entered Apprentice");
  set_long("\This is an entered apprentice for the free masons. He is a young\n\
man learning the ways of the mason. He is wearing a white leather apron.\n");
  set_level(17);
  set_hp(350 + random (75));
  set_ac(14 + random (6));
  set_wc(24 + random (6));
  set_al(0);
  set_chat_chance(10);
  load_chat(query_name()+" says, \"Hello, what are you doing here?\"\n");
  load_chat("You stand in a Mason shrine, looking around you feel inspired by what you see!\n");
  gold=clone_object("obj/money");
  gold->set_money(2000);
  move_object(gold, this_object());
  add_spell("saber","#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"saber"+NORM+" through you.\n",
                     "#MN# slices his "+HIY+"M"+HIW+"asonic"+NORM+" "+HIY+"S"+HIW+"saber"+NORM+" through #TN#.\n",
                     30,50,"other|fire");
}