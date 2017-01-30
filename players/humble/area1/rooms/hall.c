 /* COPYRIGHT (C) VITAL CORP, outline derived from Vital Code */

#include "../defs.h"

inherit "room/room";
int door;

reset(arg) {
    door = 0;
  if(!arg)
  { 
    set_light(1);
    short_desc = RED+"Hallway"+NORM;
    long_desc =
    "This is the upstairs hallway leading to, well the office.\n"+
    "There is a punchclock here for employees and a door\n"+
    "leading into the manager's office.  You can go back\n"+
    "down the stairs onto the sales floor if you wish.\n";
    items =
    ({
    "door","Perhaps you could open it and enter it?",
    "punchclock","This is the employees punchclock, if you have a timecard you could slide it",
    "stairs","A stairwell leading back down onto the sales floor",
    "hall","The hallway is very still, silent, and just down right creepy",
    });
    dest_dir =
    ({
    RPATH+"checkstand2",        "down",
    });
  }
}

init()
{
    ::init();
    add_action("open","open");
    add_action("enter","enter");
}

    open(arg) {

    if(!arg || arg == "") {
      notify_fail("What are you trying to open?\n");
      return 0;
    }

      if (arg == "door") { door = 1;
      write("You turn the doorknob and open the door to the office.\n");
      say(capitalize(this_player()->query_name())+" opens the office door.\n");
      return 1;
    }
}

    enter(arg) {

    if(!arg || arg == "") {
    notify_fail("What are you trying to enter?\n");
    return 0;
    }

    if(arg =="door") {
    if(!door == 1) {
    notify_fail("The door isn't open.\n");
    return 0;}
    this_player()->move_player("enter#/players/humble/area1/rooms/office.c");
    write("You step into the office.\n");
    say(capitalize(this_player()->query_name())+" steps into the office.\n");
    return 1;
    }
}
