#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Grana Padano");
  set_alt_name("padano");
  set_alt_name("cheese");
  set_race("dairy");
  set_alias("padano");
  set_short("Grana Padano");
  set_long("\
  Grana Padano - Stravecchio Oro del Tempo is a superb cheese\n\
Stravecchio Oro del Tempo is a superior, 22-month aged Grana\n\
Padano produced by Agriform near Venice. This masterpiece compares\n\
beautifully with its better-known cousin Parmigiano Reggiano. The\n\
flavor of Stravecchio is intense and complex, with fruity overtones\n\
that evoke pineapple or strawberry, depending on the season. Like all\n\
precious things, every Stravecchio cheese is one of a kind, and each\n\
wheel is branded with a unique serial number.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to whip you into pieces!\"\n");
  load_chat("You can not believe your eyes! The Grana Padano cheese multiplies\n\
10 times larger than its original size!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("whip","#MN# pulls out his beater and $HR$whips$N$ you up.\n",
                     "#MN# pulls out his beater and $HR$whips$N$ up #TN#.\n",
                     70,50,"other|fire");
}