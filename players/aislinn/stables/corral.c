#include "std.h"
 
object horse;
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if(!horse || !living(horse)) {
    object spurs;
      horse=clone_object("obj/monster");
      call_other(horse,"set_name","horse");
      call_other(horse,"set_alias","stallion");
      call_other(horse,"set_level",14);
      call_other(horse,"set_hp",234);
      call_other(horse,"set_wc",17);
      call_other(horse,"set_ac",4);
      call_other(horse,"set_aggressive",1);
      call_other(horse,"set_al",0);
      call_other(horse,"set_short","A powerful stallion");
      call_other(horse,"set_long",
        "A wild, unbroken stallion is glaring at you, snorting\n" +
        "and shaking it's head.  It looks like it may charge!\n");
      move_object(horse,this_object());
      spurs=clone_object("obj/treasure");
        call_other(spurs,"set_id","spurs");
        call_other(spurs,"set_alias","silver spurs");
        call_other(spurs,"set_short","A pair of silver spurs");
        call_other(spurs,"set_long",
          "An ornate pair of sterling silver spurs, so beautifully made\n" +
          "you almost forget the ugly purpose they serve.\n");
        call_other(spurs,"set_value",225);
        call_other(spurs,"set_weight",1);
        transfer(spurs,horse);
    }
}

ONE_EXIT("players/aislinn/stables/stable_path", "south",
	 "The Corral",
    "This is a large horse corral.  A watering trough is on the east\n" +
    "side and there is a large pile of hay to the south.  You can hear\n" +
    "the snorting of horses coming from the stables and the occasional\n" +
    "voice of a stable hand.\n" +
    "   \n", 1)
