#include "room.h"
#include "/players/catt/AREAS/base_defines.c"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();

extra_reset() {

}
TWO_EXIT(MOUNT+"gobpub","green",
         HALL_WORLDS+"hall5","red",
         "The Shop Nowhere",
         "You find yourself in the famous Shop Nowhere. You "+
         "see sixteen walls of metallic gray which shimmers "+
         "between silver and black. You may ask the shopkeeper "+
        "for assistance. You see a green portal and a red "+
        "portal.\n", 1)

init() {
   ::init();
   add_action("sell","sell");
   add_action("value","value");
   add_action("buy","buy");
   add_action("list","list");
}

sell(arg) {

}

value(arg) {

}

buy(arg) {

}

list(arg) {

}

