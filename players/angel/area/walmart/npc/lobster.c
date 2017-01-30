#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("lobster");
  set_alt_name("fish");
  set_race("fish");
  set_alias("lobster");
  set_short("Carolina Lobster");
  set_long("\
  When the lobsters are this fresh, it’s okay to drool a little.\n\
Our lobsters are caught in the morning off the coast of Maine and\n\
Nova Scotia and shipped live from the dockside to our stores. All\n\
you have to do is round up your friends and stock up on lobster\n\
bibs and napkins. Our lobsters are available in weights from 1.25\n\
to 5 lbs. These lobsters are so fresh you better Beware or you may\n\
get bit.\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to snap you apart!\"\n");
  load_chat("You can not believe your eyes! The lobster just grew 8 feet tall!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("bite","#MN# swings its claws $HR$snapping$N$ you apart.\n",
                     "#MN# swings its claws $HR$snapping$N$ apart #TN#.\n",
                     70,50,"other|water");
}