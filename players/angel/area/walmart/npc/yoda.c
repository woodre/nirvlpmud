#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Yoda");
  set_alt_name("figure");
  set_race("action figure");
  set_alias("yoda");
  set_short("Yoda");
  set_long("\
  Jedi Master Yoda is the wisest and most powerful of all the Jedi.\n\
For over 800 years, he has trained students in the ways of the\n\
Force. Now this amazing teacher tells stories, tests your knowledge\n\
and answers your questions! Feel the power of the Force! Ask\n\
assistance from the wisest Jedi of all? Yoda actually 'comes alive'\n\
when activated.\n");
  set_level(24);
  set_hp(660 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(100);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"young Jedi's need further guidance of course?\"\n");
  load_chat("You feel the presence of the force move through you!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("laser","#MN# slices his light $HG$saber$N$ through you.\n",
                     "#MN# slices his light $HG$saber$N$ through #TN#.\n",
                     70,60,"other|laser");
}