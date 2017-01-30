#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Blurr");
  set_alt_name("transformer");
  set_race("transformer");
  set_alias("blurr");
  set_short("Blurr");
  set_long("\
    BLURR is a former race champion, He retired years ago and has\n\
since made a career coaching younger speedsters in the subtleties\n\
of racing. He is a tough teacher, with a gruff personality that\n\
often comes across as bad tempered to those who don’t know him.\n\
He is tough on those who come to him for training because he takes\n\
their successes and  failures personally, and he requires no less\n\
of his students and himself - than their best. Blurr can change\n\
from futuristic racer into heroic robot with supersonic firing\n\
projectiles! Save Cybertron!\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"We must find the key and save Cybertron!\"\n");
  load_chat("Change up! Convert to robot mode.\n");
  load_chat("Fire up the turbo-rocket launchers!\n");
  load_chat("I alway hit my target with my firing projectiles!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("projectiles","#MN# fires high powered supersonic $HR$projectiles$N$ at you.\n",
                     "#MN# fires high powered supersonic $HR$projectiles$N$ at #TN#.\n",
                     90,20,"other|fire");
}