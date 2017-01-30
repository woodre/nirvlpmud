#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Nave");
  set_long("\
The Cathedral's long nave stretches out between the large portal to the south, and \
the crossing to the north.  Colored light streams in through the enourmous circular \
stained glass window above the doors, and from the clerestory windows, high overhead.  \
The floor is of white marble, but a wide carpet begins at the portal and runs northward down the \
center of the nave, towards the crossing.  \
To the east and west, tall arches supported by graceful columns seperate the nave \
from the aisles, and a taller row of columns seperates the crossing, to the north.  \
A number of pews sit in rows, facing north.\
");

  set_light(1);

  add_item("crossing","It's to the north.");
  add_item("cathedral","You're inside it.");
  add_item("nave","Yep, you're in the nave.");
  add_item("portal","An enourmous arch, filled with two huge wooden doors.  A smaller inner door provides a more convenient way to enter and exit the cathedral.");
  add_item("doors","Huge wooden doors, inlaid in beautiful golden patterns.");
  add_item("patterns","For some reason, staring at the patterns too long makes your pulse start to race.");
  add_item("inner door","A reasonably sized door for entering and exiting the cathedral, set inside the much larger ones.  It's unlocked.");
  add_item("window","A beautifully-colored stained glass window.  It depicts a man and a woman, each reclining on their size of the window, facing each other.  Both bodies are well-proportioned, and their faces are as flawless as the stylized medium allows.  The work is so perfect that the scene is repeated in light on the floor of the nave.");
  add_item("windows","The clerestory windows are inlaid in a variety of abstract patterns.  Light slants in from both sides, bathing both the sides of the nave and the aisles in beautiful light.");
  add_item("light","The colored light from the windows illuminates the whole interior of the nave, and the aisles as well, as though the sun is shining in from three directions at once.");
  add_item("clerestory","The roof of the nave vaults far above the roof of the adjoining aisles, allowing for wide windows that admit additional light.");
  add_item("roof","The roof of the nave is a series of converging vaults, decorated in gold.");
  add_item("floor","Immaculate white marble.");
  add_item("marble","It looks like pure white marble, but it is warm to the touch, and far softer than natural stone ought to be.");
  add_item("carpet","A luxuriously deep and soft red velvet carpet.");  
  add_item("pews","The pews are enourmous, really more like large couches, so there are only a few of them.  They are upholstered in red velvet, with several additional cushions per pew.");
  add_item("arches","They help to hold up the clerestory.");
  add_item("columns","Columns of white marble line the nave.");
  add_item("aisles","The aisles run up either side of the cathedral, east and west.");
  
  set_etime_const(600);
  set_etime_rand(120);
  add_room_emote("The brightly-colored beams of light shift slowly across the floor.");
  add_room_emote("A soft, passionate moan can be heard echoing from somewhere in the cathedral.");  
  
  add_exit("north",ROOM+"crossing");
  add_exit("west",ROOM+"nave_aisle_west");
  add_exit("east",ROOM+"nave_aisle_east");
  add_exit("south",ROOM+"facade");
    
}

void init() {
  ::init();
}