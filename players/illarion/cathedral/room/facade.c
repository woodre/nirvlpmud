#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Facade");
  set_long("\
This is the facade, or main entrance, of a large stone cathedral.  Directly to the north, the cathedral's\
 portal dominates the front of the building, but the circular stained glass window above it is only\
slightly smaller.  To either side of the portal is a square tower, stretching upward above the\
cathedral's highly vaulted roof.\
");

  add_item("cathedral","You're just outside it.");
  add_item("facade","A fancy name of the fancy front of the building.");
  add_item("portal","An enourmous arch, filled with two huge wooden doors.  A smaller inner door provides a more convenient way to enter and exit the cathedral.");
  add_item("doors","Huge wooden doors.  Despite being outdoors, they seem like new.");
  add_item("inner door","A reasonably sized door for entering and exiting the cathedral, set inside the much larger ones.  It's unlocked.");
  add_item("stone","Grey, hard, cold.");
  add_item("window","A beautifully-colored stained glass window.  It depicts a man and a woman, each reclining on their size of the window, facing each other.  Both bodies are well-proportioned, and their faces are as flawless as the stylized medium allows.");
  add_item("tower","Square stone towers.  They look very solid.");
  add_item("roof","You can see the roof is steeply sloped from down here, but that's about it.");
  
  set_light(1);
  
  add_exit("north",ROOM+"nave");
    
}

void init() {
  ::init();
}
