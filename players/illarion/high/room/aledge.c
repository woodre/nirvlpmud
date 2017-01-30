/*****************************************
| One person room:  if more than two objects are in the room
| when init() is called, everything in the room gets moved to
| high/room/wagon
*********************************************/
inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A narrow ledge";
  long_desc=
"You are balanced precariously on a narrow ledge outside a leaded window.\n"+
"To either side, the ledge tapers away into the wall, but fortunately\n"+
"there seems to be a hay wagon below.  Further off in the distance, you\n"+
"can see a fence, and a line of trees.\n";

  items= ({
    "ledge","A row of stones that protrude slightly from the wall.  So\n"+
            "slightly, in fact, that you sway a bit from looking at it",
    "window","Leaded windowpanes, swung outward to one side,\n"+
             "and white lace curtains inside",
    "wagon","A wagon filled with hay.  It would break a fall, but probably\n"+
            "give you a wonderful case of the itches",
    "fence","A goodly ways away, it probably marks the edge of someone's land",
    "trees","The trees look thick and dark, a good place to hide",
  });
  dest_dir= ({
    HROOM+"abedroom","window",
    HROOM+"wagon","down",
  });
}
void init() {
  object *ppl;
  int size;
  ::init();
  size=sizeof((ppl=all_inventory(this_object())));
  if(size > 1) {
    tell_room(this_object(),"The ledge has gotten too crowded!\n");
    call_out("all_fall_down",0);
  }
}
all_fall_down() {
  object *ppl; int size,x;
  size=sizeof((ppl=all_inventory(this_object())));
  for(x=0;x<size;x++) ppl[x]->move_player("down#"+HROOM+"wagon");
/* for non-living items, do it again using transfer */
    size=sizeof((ppl=all_inventory(this_object())));
  for(x=0;x<size;x++) transfer(ppl[x],HROOM+"wagon");
}
