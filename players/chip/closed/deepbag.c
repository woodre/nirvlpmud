/* wanting to make this bag for neo symbiotes only. it will take up the empty slot for
   LvL4 Creation, perhaps entwine it so you also need 5 or 6 in Control. would cost
   around 300 mp, 150-200 sp, and perhaps a cash cost. also want to make it owner
   only, so no one else can go and just pick it up if it gets left somewhere */

inherit "obj/container.c";
#include "/players/chip/ansi.h"

  reset(arg) {
    ::reset(arg); 
    if (arg) return;
    set_name("bag");
    set_short("A bag composed of "+BOLD+"[ "+HIK+"Dark Matter"+NORM+BOLD+" ]"+NORM);
   set_long(
      "This bag is nothing more than a swirling mass of "+HIK+"Dark Matter"+NORM+". It can\n"+
      "hold almost anything, and seems to emit an odd glowing energy. It belongs\n"+
      "to ??\n"); /*want to replace ?? with owner's name*/
    set_light(4);
    set_weight(1);
    set_value(0);
    set_max_weight(2000);
}
