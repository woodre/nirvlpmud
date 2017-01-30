#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Western Aisle");
  set_long("\
The aisles are the lower-ceilinged areas along the cathedral's east and west walls.  \
This section of the eastern aisle borders on the sanctuary.  It continues to the \
south, and ends at the ambulatory in the north.  This section of the aisle is somewhat \
shadowy, and a few candles have been installed along the wall, providing a little bit of \
light for a pair of couches.\
");
  
  add_item("wall","The outer walls of the cathedral are made of grey stone.");
  add_item("candles","Thick white candles, burning steadily.  They smell fainly of lavender.");
  add_item("couches","Low, large couches.  They look insanely comfortable.");  set_long("");
 
  set_light(1);

  add_exit("north",ROOM+"ambulatory");
  add_exit("east",ROOM+"sanctuary");
  add_exit("south",ROOM+"choir_aisle_west");

}

void init() {
  ::init();
}