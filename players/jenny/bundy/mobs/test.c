inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("cockroach");
    set_alt_name("roach");
    set_race("insect");
set_alias("bug", "test");
    set_al(-10);
    set_level(2);
    set_hp(22+random(6));
    set_wc(6);
    set_ac(5);
    set_short("A cockroach");
    set_long(
      "An ugly cockroach.  These are resilient creatues who are hard\n"+
      "to get rid of once they invade a house.  There are many\n"+
     "cockroaches in the Bundy house.\n");
MOCO("/players/jenny/bundy/items/eggs.c"),this_object());  }
