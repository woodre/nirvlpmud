#include "std.h"

object man;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
  if(!man || !living(man)) {
  object weapon;
    man=clone_object("obj/monster");
    call_other(man, "set_name","man");
    call_other(man,"set_alias","tresspasser");
    call_other(man,"set_level",3);
    call_other(man,"set_hp",77);
    call_other(man,"set_wc",5);
    call_other(man,"set_ac",3);
    call_other(man,"set_aggressive",1);
    call_other(man,"set_al",-100);
    call_other(man,"set_short","A tresspasser");
    call_other(man,"set_long",
     "A shifty-eyed man looks at you from the corner, tightly gripping\n" +
     "a pitchfork and preparing to kill you!\n",1);
    move_object(man,this_object());
    weapon=clone_object("obj/weapon");
    call_other(weapon,"set_name","pitchfork");
    call_other(weapon,"set_short","A pitchfork");
    call_other(weapon,"set_long",
      "A pitchfork, with sharply honed tines, but abit unwieldy.\n");
    call_other(weapon,"set_class",8);
    call_other(weapon,"set_value",80);
    call_other(weapon,"set_weight",5);
    transfer(weapon,man);
  }
}
 
ONE_EXIT("players/aislinn/stables/stable_ent", "down",
	 "Stable Loft",
    "The loft of the stables is one huge room.  There are doors at either\n" +
    "end, presumably for loading and unloading.  Bales of hay are stacked\n" +
    "along one wall and there is a large pile of it just begging for some\n" +
    "adventurer to lay in and fall asleep.  The sounds of the horses and\n" +
    "workers below is muted...\n" +
    "   \n", 1)
