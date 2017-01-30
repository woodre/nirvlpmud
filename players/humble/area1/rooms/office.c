/* COPYRIGHT (C) VITAL CORP, outline derived from Vital Coce */

#include "../defs.h"
int door;
inherit "room/room";

reset(arg) {
    door=0;
  if(!arg)
  { 
    set_light(1);
    short_desc = MAG+"Office"+NORM;
    long_desc =
    "This is the upstairs office.  There are several desks here\n"+
    "along with several chairs.  On top of one of the desks is a\n"+
    "set of computers sitting side by side.  Above the desk are\n"+
    "small gun shaped items called SPAs used for pricing of items.\n"+
    "There is a door out of the office and another door adjacent to it\n"+
    "where a sign hangs.\n";

    items =
    ({
    "desk","There are about 4 desks in this small office",
    "desks","There are about 4 of them in this small office",
    "SPA","Yeaaahhhh budday!",
    "door","There are two doors here, one you came in, one that you didn't come in",
    "computers","There are two computers sitting side by side, probably for a good reason",
    "chairs","Lots of chairs in here, maybe you could take one for a spin",
    });
    dest_dir =
    ({
    RPATH+"hall",        "out",
    });

    move_object(clone_object("players/humble/area1/mobs/roberta.c"), this_object());
  }
}

init()
{
    ::init();
    add_action("open","open");
    add_action("enter","enter");
}

    open(arg) {

    if(!arg == "") {
      notify_fail("What do you want to open?\n");
      return 0;
    }

    if(arg =="door") { door = 1;
    write("You twist the knob and open up the door leading to the computer room.\n");
      say(capitalize(this_player()->query_name())+" opens up the door to a dark room.\n");
    return 1;
    }
}

    enter (arg) {

    if(!arg || arg == "") {
    notify_fail("You just walked into the door, smart.\n");
    return 0;
    }

    if(arg == "door") {
    if(!door == 1) {
    notify_fail("You just walked into the door, smart.\n");
    return 0;}
    this_player()->move_player("enter#/players/humble/area1/rooms/comproom.c");
    write("You walk into a dark room.\n");
    say(capitalize(this_player()->query_name())+" steps into the shadows of a dark room.\n");
    return 1;
    }
}
