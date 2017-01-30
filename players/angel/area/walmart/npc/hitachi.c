#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Hitachi");
  set_alt_name("tv");
  set_alt_name("plasma");
  set_race("television");
  set_alias("Hitachi");
  set_short("Hitachi plasma TV");
  set_long("\
  55 inch plasma display: Enjoy impressive big-screen images\n\
from a slender TV. Plasma TV's also offer tremendous placement\n\
flexibility, even with a large 55' screen. The built-in high\n\
definition tuner makes it simple to access brilliant HD\n\
programming. TV shows, movies and sporting events will take on\n\
a whole new 'life'.\n");  
  set_level(21);
  set_hp(560 + random (100));
  set_ac(22 + random (9));
  set_wc(37 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am as big as they come!\"\n");
  load_chat("You have the strangest urge to sit on your sofa and grab the remote!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("Plasma","#MN# sends out Radioactive $HR$WAVES$N$ through you.\n",
                     "#MN# sends out Radioactive $HR$WAVES$N$ through #TN#.\n",
                     80,30,"other|sonic");
}