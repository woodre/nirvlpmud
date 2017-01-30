#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("hog");
  set_alt_name("pig");
  set_alt_name("hatfield");
  set_race("pig");
  set_alias("hog");
  set_short("Hatfield Hog");
  set_long("\
  This is a whole hog gutted and cleaned that hangs in the meat\n\
freezer until it is processed by Hatfield's Meats. Hatfield\n\
Quality Meats has been producing wholesome great-tasting products\n\
since the early 1900’s. Their modern equipment and extremely high\n\
food safety standards allow them to consistently provide customers\n\
with the freshest quality. With Hatfield’s Fresh Check Guarantee,\n\
nobody will ever have to guess if their pork has passed its prime.\n\
Just check the package for the 'freshest taste by' date and always\n\
know you’re serving the best.\n");
  set_level(21);
  set_hp(560 + random (200));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"I am going to hang you like a piece of meat!\"\n");
  load_chat("You can not believe your eyes! The hog jumps off its hook\n\
and swings it around!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("hook","#MN# swings its $HR$hook$N$ into you.\n",
                     "#MN# swings its $HR$hook$N$ in #TN#.\n",
                     90,30,"other|fire");
                     
                     
}