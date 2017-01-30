inherit "/players/illarion/room";
#include "/players/illarion/dfns.h"
void reset(int arg) {
  if(!present("inspector",this_object()))
    move_object(clone_object(HMON+"inspector"),this_object());
  if(arg) return;
  set_light(1);
  set_short("The deck of a black barge");
  set_long(
"A barge the size of a small house is tied up close to the side of the river, "+
"serving as a dwelling.  A good coat of blank paint serves to waterproof the "+
"metal and wood construction of the barge.  The only features of the barge's top "+
"are a long-unused steeringhouse, and the door leading below.  On the "+
"eastern side of the barge, a gangplank leads back to shore.");
  add_item("barge","An old, but solid barge, that hasn't been used to carry "
                  +"cargo for quite a while.");
  add_item("river","A picturesque river, but a bit polluted.");
  add_item("paint","The barge is painted a uniform shade of utilitarian "
                  +"black.");
  add_item("steeringhouse","Once used by the man steering the barge as it "
                          +"was pushed up and down the river, it has stood "
                          +"empty and useless for years.");
  add_item("door","A small door in the side of part of the barge protruding "
                 +"upward from the deck.  It's rather short as most of the "
                 +"barge's volume is below decks.");
  add_item("gangplank","A wooden board run between the barge and the shore.");
  add_item("shore","The bank here is entirely covered in old-looking stone.");

  add_exit("east",HROOM+"bank");
  add_exit("down",HROOM+"inbarge1");
}
