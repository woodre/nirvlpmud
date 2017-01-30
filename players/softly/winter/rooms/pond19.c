#include "/players/softly/misc/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("daniel")) 
  move_object(clone_object("players/softly/winter/daniel.c"),this_object());
  if(arg) return;
  set_light(1);

  short_desc = "A Frozen Cottage";
  long_desc ="  The inside of the tiny cottage is tidy and very normal\n"+ 
             "except that everything inside it is made of ice.  The\n"+
             "fireplace is not melted in spite of a raging fire.  A\n"+
             "small table holds a few dishes and several photographs.\n";

  items = ({
    "ice", "The ice is clear and thick, as if it had existed for along time",
    "fireplace", "A large ice fireplace contains a raging fire",
    "table","A dining table with a single place setting of dishes\n"+
            "and two photographs in ornate frames",
    "photographs","One photograph is of two beautiful children playing in a lake.\n"+
                  "The other is a simple wedding photograph of a happy couple",
  });

  dest_dir = ({
    "/players/softly/winter/rooms/pond18.c","leave",
  });
}
