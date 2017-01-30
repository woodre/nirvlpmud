#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Polan");
  set_alt_name("chainsaw");
  set_alt_name("saw");
  set_race("Chain saw");
  set_alias("polan");
  set_short("Polan Pro");
  set_long("\
  Polan Pro 46 has a quick adjust easy chain tensioning system.\n\
With a chain brake that stops the chain from moving when\n\
activated. It has DuraLife Cylinder for longer engine life and\n\
super clean engine performance system that provides longer air\n\
filter life. The Anti-Vibe handle to reduces operator fatigue\n\
and helps to saw things to pieces.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am about to saw you into pieces!\"\n");
  load_chat("You can smell the fresh cut wood in the air!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("blade","#MN# $HR$saws$N$ you down.\n",
                     "#MN# $HR$saws$N$ down #TN#.\n",
                     80,40,"other|fire");
}