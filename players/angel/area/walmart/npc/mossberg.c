#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Mossberg");
  set_alt_name("gun");
  set_alt_name("935");
  set_race("Gun");
  set_alias("mossberg");
  set_short("Mossberg 935");
  set_long("\
  This is the Mossberg 935 Magnum semi-automatic 3 1/2' chambered\n\
shotgun. Its pedigree is downright legendary. Its price and\n\
performance well, they speak for themselves! It is a hard core,\n\
workhorse shotgun designed to send out only the hardest hitting 3'\n\
and 3 1/2' payloads. This is the kind of medicine that it takes to\n\
put meat on the table.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am about to shoot you into pieces!\"\n");
  load_chat("You can smell the fresh gun powder in the air!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("bullet","#MN# $HR$shoots$N$ you down.\n",
                     "#MN# $HR$shoots$N$ down #TN#.\n",
                     80,40,"other|fire");
}