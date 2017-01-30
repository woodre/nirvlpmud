#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("fried chicken");
  set_alt_name("chicken");
  set_alt_name("fried");
  set_race("poultry");
  set_alias("chicken");
  set_short("Fried Chicken");
  set_long("\
  This is fresh fried chicken, never frozen, so you get a\n\
delicious meal every time! Our secret breading recipe makes\n\
Wal-Mart's fried chicken the best-tasting chicken in town.\n\
Choose from packages containing 8, 16, 24, 50 or even 100\n\
pieces of our incredible fried chicken. It’s made fresh all\n\
throughout the day!\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to peck you to death!\"\n");
  load_chat("You can not believe your eyes! The fried chicken jumps out of the\n\
pan and jumped on your head!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("peck","#MN# jumps on your head and $HR$pecks$N$ you to death.\n",
                     "#MN# jumps on your head and $HR$pecks$N$ apart #TN#.\n",
                     50,60,"other|fire");
}