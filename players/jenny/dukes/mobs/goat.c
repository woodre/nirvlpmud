inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("goat");
    set_race("animal");
    set_alias("A goat");
    set_al(0);
    set_level(6);
    set_hp(90+random(8));
    set_wc(9);
    set_ac(6);
    set_short("A goat");
    set_long(
      "This is a goat that lives on the Duke farm.  They\n"+
    "use it to produce goat's milk.\n");
MOCO("/players/jenny/dukes/items/milk.c"),this_object());  }
