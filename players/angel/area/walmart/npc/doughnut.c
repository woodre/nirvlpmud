#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("glazed doughnut");
  set_alt_name("doughnut");
  set_race("pastry");
  set_alias("doughnut");
  set_short("Glazed Doughnut");
  set_long("\
  This doughnut is an original Krispy Kreme glazed doughnut\n\
When people talk about a Krispy Kreme doughnut, they're\n\
usually referring to our signature treat: the Original Glazed.\n\
Made from a recipe dating back to the 1930s, our Original\n\
Glazed doughnuts have helped set us apart. And if you haven't\n\
had an Original Glazed HOT off the line, you need to try one!\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to smack you around like a piece of meat!\"\n");
  load_chat("You can not believe your eyes! The doughnut is\n\
rising to over 6 feet high!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("smack","#MN# grabs the $HR$ladle$N$ and smacks you down.\n",
                     "#MN# grabs the $HR$ladle$N$ and smacks down #TN#.\n",
                     30,80,"other|fire");
}