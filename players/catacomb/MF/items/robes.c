#include "/players/catacomb/misc/ansi.h"
inherit "/obj/armor";

reset(arg) 
{
  if(arg) return;
  set_name("robe");
  set_short("A mystical robe");
  set_long(
   "The long flowing robes of a Shamot priest.  The robes are said\n"+
   "to protect it wearer from the evils of the land.\n");
  set_type("armor");
  set_ac(3);
  set_weight(2);
  set_value(1500);
  set_params("other|evil", 1, 10, "do_evil_special");
}

int
do_evil_special(object owner)
{
  if (random (10) >= 9)
  {
    tell_object(owner, 
     "\n       Your shield absorbs the damage from the evil being.\n");
    return 0501;
  }
}
