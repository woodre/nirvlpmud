#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("orange");
  set_race("produce");
  set_alias("orange");
  set_short("Regal Navel Orange");
  set_long("\
  This large juicy Regal Navel Orange is a prized gems of the\n\
citrus world. Regal Navel Oranges have a flavor suggesting\n\
honeydew melon, mango, pineapple and papaya. They are a mouth\n\
watering fresh fruit and you can surprise your own family with\n\
the famous taste of 'Florida sunshine'.  Our citruses are available\n\
in four convenient sizes.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to shoot you to pieces!\"\n");
  load_chat("You can not believe your eyes! The Orange grows to 10 feet tall!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("shoot","#MN# $HR$shoots$N$ you to pieces with seeds.\n",
                     "#MN# the Regal Navel Orange $HR$hooks$N$ up #TN#.\n",
                     35,70,"other|earth");
}
