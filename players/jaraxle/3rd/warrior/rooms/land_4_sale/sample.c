#include "defs.h"

/*
 * Land needs to be inherited as well as whatever room inherit you use.
 */
inherit "/players/earwax/housing/land";
inherit "/room/room";

void reset(status arg) {

  if (arg)
  {
    ::reset(arg);
    return;
  }

  /* 
   * Throw your basic room information up here.
  */

  short_desc = "Player Housing System Test Room";
  long_desc = "This is a testing room.  Fear this shit.\n";

  /*
   * The 4 functions needed to make room land:
   *
   * set_cost(amount) .... how much for the land itself.
   *
   * set_realm_name(name) .... what the area is called...
   *   ie: "Fallen Lands"
   *
   * set_lot_size(1,2,3,6,9,-2):
   *   1,2,3 are small land....if you want it only to have a 
   *   1 room shack, use 1, a 2 room hut or a 1 room shack, use 2,
   *   3 room trailer or a shack or hut, use 3.....for house only, use
   *   6, for house or mansion use 9....for very large land, use -2
   * setup_land() ... sets it all up.
  */
  set_cost(150000);
  set_realm_name("Wastelands");
  set_lot_size(6);
  setup_land();

}
