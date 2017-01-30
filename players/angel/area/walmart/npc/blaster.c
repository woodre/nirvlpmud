#include <ansi.h>

inherit "obj/monster";

reset(arg)
{
  object gold,armor,weapon;
  ::reset(arg);
  if(arg) return;
  set_name("Blaster");
  set_alt_name("transformer");
  set_race("transformer");
  set_alias("blaster");
  set_short("Blaster");
  set_long("\
    Blaster is a wild outlaw, rugged villain of the rough\n\
backwaters of the Speed Planet; those who are fooled by the\n\
sheer size of dirt boss into thinking he’s slow are soon left\n\
choking on his exhaust. He lives to pound his opponents into\n\
the dust and leave them spinning their wheels. That’s if he\n\
decides to leave the wheels attached. Save Cybertron!\n");
  set_level(21);
  set_hp(560 + random (100));
  set_ac(20 + random (9));
  set_wc(38 + random (9));
  set_al(0);
  set_chat_chance(15);
  load_chat(query_name()+" says, \"We must find the key and save Cybertron!\"\n");
  load_chat("Change up! Convert to robot mode.\n");
  load_chat("Fire up the turbo-rocket launchers!\n");
  load_chat("I always hit my target with my supersonic firing projectiles!\n");
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  armor=clone_object("/players/angel/area/walmart/obj/money.c");
  move_object(armor, this_object());
  add_spell("projectiles","#MN# fires high powered supersonic $HR$LASER$N$ gun at you.\n",
                     "#MN# fires high powered supersonic $HR$LASER$N$ gun at #TN#.\n",
                     50,60,"other|laser");
}
