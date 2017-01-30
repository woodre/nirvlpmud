inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;
  
  set_light(1);
  set_short("A "+HIG+"tropical"+NORM+" honeymoon villa");
  set_long(
     "The counters and cabinets in this room would seem to make it a kitchen, "
    +"but it seems to be lacking a sink, oven, and stove.  Instead, there's "
    +"an odd-looking contraption sitting on the counter in the southwest "
    +"corner of the room.  To the north, a door leads to the hallway, and "
    +"to the east, a doorway opens into the dining area.");
  
  add_item("counter","The counters are long and spotless, even unused.  A "
                    +"few drawers underneath hold only eating utensils.");
  add_item("cabinets","The cabinets are well made, but a look inside shows "
                     +"only the types of dishes used for eating and serving, "
                     +"none for cooking.");
  add_item("contraption","A very enigmatic boxed shaped machine.  A closer "
                        +"examination reveals that it's replicator/dishwasher "
                        +"of some kind.  Looks like someone has been raiding "
                        +"a science fiction series for ideas.");
                        
  add_exit("hall",VILLA+"hall");
  add_exit("dining",VILLA+"dining");
}
