#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Choir");
  set_long("\
The choir is the last approach to the cathedral's sanctuary.  It is bordered \
by columns to the east and west seperating from the aisles, and there is a row of taller columns \
to the south seperating it from the crossing.  A red carpet runs north from the crossing \
towards the sanctuary, where you can see an altar with two large statues behind it.  \
Above the aisles, stained glass windows in the clerestory allow light to shine down.\
");
  
  set_light(1);

  add_item("choir","You're in the choir.");
  add_item("sanctuary","It's to the north.");
  add_item("roof","The roof of the choir is a series of converging vaults, decorated in gold.");
  add_item("floor","Immaculate white marble.");
  add_item("marble","It looks like pure white marble, but it is warm to the touch, and far softer than natural stone ought to be.");
  add_item("carpet","A luxuriously deep and soft red velvet carpet.");  
  add_item("arches","They help to hold up the clerestory.");
  add_item("columns","Columns of white marble line the choir.");
  add_item("stalls","Large wooden chairs, more like couches, really, sized to hold at least two peopple in great comfort.  There are six stalls to each side of the carpet, arranged in semi-circular fashion.");
  add_item("aisles","The aisles run up either side of the cathedral, east and west.");
  add_item("altar","You might as well continue to the sanctuary and get a better look.");
  add_item("statues", "You might as well continue to the sanctuary and get a better look.");
  add_item("windows","The clerestory windows are inlaid in a variety of abstract patterns.  Light slants in from both sides, bathing both the aisles in beautiful light, but leaving the stalls in soft shadow.");
  add_item("clerestory","The roof far above the roof of the adjoining aisles, allowing for wide windows that admit additional light.");
  
  add_exit("north",ROOM+"sanctuary");
  add_exit("west",ROOM+"choir_aisle_west");
  add_exit("east",ROOM+"choir_aisle_east");
  add_exit("south",ROOM+"crossing");

  set_etime_const(600);
  set_etime_rand(120);
  add_room_emote("The brightly-colored beams of light shift slowly across the floor.");
  add_room_emote("A soft, passionate moan can be heard echoing from somewhere in the cathedral.");  

  
}

void init() {
  ::init();
}