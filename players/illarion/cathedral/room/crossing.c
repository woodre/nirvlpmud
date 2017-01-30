#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral Crossing");
  set_long("\
Between the nave to the south and the choir to the north is the cathedral's crossing, \
a perfectly square area surrounded by columns and surmounted by a dome.  Around the base \
of the dome are a number of circular windows.  A wide red carpet running north to south \
is flanked by a number of statues.  Between the statues, the aisles and the colums running \
along them are visible.\
");

  set_light(1);
  
  add_item("crossing","You're in it.");
  add_item("nave","It's to the south.");
  add_item("choir","It's to the north.");
  add_item("cathedral","You're inside the cathedral.");
  add_item("dome","A beautiful dome.  It is covered with a brilliantly-colored mural.");
  add_item("mural","The mural depicts an absolutely stunning man and woman locked in a passionate embrace.");
  add_item("windows","Round, stained glass windows.  Light enters through all of them regardless of the time of day or the weather outside, creating an interlocking pattern on the floor.");
  add_item("pattern","The overlapping patterns of light on the floor, when examined closely, suggest a series of embracing figures.");
  add_item("marble","It looks like pure white marble, but it is warm to the touch, and far softer than natural stone ought to be.");
  add_item("carpet","A luxuriously deep and soft red velvet carpet.");
  add_item("statues","The statues alternate between male and female.  Each statue is different, but all are stunningly beautiful in both face and figure, and each seems to be seamlessly carved from white marble.");
  add_item("aisles","The aisles run up either side of the cathedral, east and west.");
  add_item("columns","Columns of white marble line the crossing.  The ones to the north and south are taller, and larger, reaching all the way to the bottom of the windows under the dome.");

  set_etime_const(600);
  set_etime_rand(120);
  add_room_emote("The brightly-colored beams of light shift slowly across the floor.");
  add_room_emote("A soft, passionate moan can be heard echoing from somewhere in the cathedral.");  

  add_exit("north",ROOM+"choir");
  add_exit("west",ROOM+"crossing_aisle_west");
  add_exit("east",ROOM+"crossing_aisle_east");
  add_exit("south",ROOM+"nave");
    
}

void init() {
  ::init();
}