#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET set_blanket();
 
set_blanket() {
  object blanket;
  blanket = present("horse blanket");
  if(!blanket) {
    blanket=clone_object("obj/treasure");
    call_other(blanket,"set_id","blanket");
    call_other(blanket,"set_alias","horse blanket");
    call_other(blanket,"set_short","A horse blanket");
    call_other(blanket,"set_long",
      "A once beautiful saddle blanket, finely made but now now somewhat\n" +
      "tattered and frayed.\n",1);
    call_other(blanket,"set_value",100);
    call_other(blanket,"set_weight",2);
    move_object(blanket,this_object());
  }
}
 
ONE_EXIT("players/aislinn/stables/stable1", "east",
	 "Horse Stall",
    "This is a large, fairly spacious horse stall.  There is a layer of\n" +
    "hay on the floor, and a water trough and food bin along the back\n" +
    "wall.  The smell of horses is strong and there is evidence that this\n" +
    "stall was recently in use.\n" +
    "    \n", 1)
