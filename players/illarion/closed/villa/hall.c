inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "A long hallway leads through the villa here, sparsely furnished with "
    +"a couple of tables trimmed with shells, and some framed pictures "
    +"along the walls.  The door to the land side of the villa is just "
    +"to the west, and to the east the hall ends in a large room, while two "
    +"more doors open to the north and south.");
    
  add_item("tables","Small, thin tables set along the wall, made from some "
                   +"exotic wood, and trimmed with seashells.");
  add_item("pictures","The picture frames hold photographs and paintings of "
                     +"the beach and jungle.");
  add_item("room","The living area of the villa is just to the east.");
  add_item("doors","The door to the north leads to the bedroom, and the one "
                  +"to the south to the kitchen.");

  add_exit("west",VILLA+"entrance");
  add_exit("east",VILLA+"living");
  add_exit("north",VILLA+"bedroom");
  add_exit("south",VILLA+"kitchen");
}
