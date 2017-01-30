inherit "/obj/monster";
#include "/players/jenny/define.h"
reset(arg)
{
   ::reset(arg);
    if (arg) return;
    set_name("chicken");
    set_alt_name("hen");
    set_race("bird");
    set_alias("A chicken");
    set_al(0);
    set_level(3);
    set_hp(40+random(10));
    set_wc(7);
    set_ac(4);
    set_short("A chicken");
    set_long(
      "This is one of the many chickens that live on the Duke\n"+
      "farm.  It is a small white bird that is good for laying eggs\n"+
     "until it becomes a nice fried chicken dinner.\n");
MOCO("/players/jenny/dukes/items/egg.c"),this_object());  }
