inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(!present("xavier",this_object()))
    move_object(clone_object(HMON+"xavier"),this_object());
  if(arg) return;

  set_short("A smoky battlefield");
  set_long("\
This is a smoky, noisy, stinky, battlefield.  The fighting has moved away from this \
area, but there are dead bodies strewn all around, surrounding a large truck.  \
In all the confusion, it's impossible to see any other part of the battle, although \
the sounds if it are all around you.");

  add_item("smoke","It's smokey.  And it stinks.");
  add_item("battlefield","Definately a battlefield.");
  add_item("truck","It appears to be a payroll truck, but it's been plundered.  Only one box remains.");
  add_item("box","You could try to "+BLD("open")+" the box.");
  add_item("bodies","Most of them have no apparent wounds, but a suspicous froth around the mouth.");
  add_item("battle","Nope, you can't see the battle.");

  add_exit("south",HROOM+"battlefield");
  add_exit("north",HROOM+"battlefield");
  add_exit("east",HROOM+"battlefield");
  add_exit("west",HROOM+"battlefield");
}

void init() {
  ::init();
  add_action("cmd_open","open");
}

status cmd_open(string arg) {
  if(arg != "box") FAIL("Open what?\n");
  write("You open the box, and the battlefield disappears!");
  this_player()->move_player("into the truck, and then vanishes#"+HROOM+"living");
  return 1;
}