#include "../def.h"

inherit "/players/illarion/room";

void reset(status arg) {
  if(arg) return;
  
  set_short("The Cathedral's Eastern Aisle");
  set_long("The aisles are the lower-ceilinged areas along the cathedral's east and west walls.\
This section of the eastern aisle borders on the nave, running from the facade to the \
south to and further into the cathedral to the north.  Light from the nave's clerestory \
keeps this part of the aisle well-lit, illuminating the paintings affixed to the wall.  \
Nearly hidden in the corner is a staircase leading upwards.\
");
  
  add_item("wall","The outer walls of the cathedral are made of grey stone.");
  add_item("clerestory","The upper section of the cathedral, where windows let in light.");
  add_item("paintings","A number of paintings of heart-breakingly handsome men.");
  add_item("staircase","It's narrow and dark, but probably passable.");

  set_light(1);

  add_exit("north",ROOM+"crossing_aisle_east");
  add_exit("west",ROOM+"nave");
  add_exit("up",ROOM+"tower_east");
  
    
}

void init() {
  ::init();
  add_action("up_emote","up");
}

status up_emote() {
  write("You climb up several flights of stairs and arrive at the top of the tower.\n");
  return 0;
}