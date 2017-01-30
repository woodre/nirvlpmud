#include "/players/softly/closed/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("diary")) 
  move_object(clone_object("players/softly/point/obj/diary.c"),this_object());
  if(arg) return;

set_light(1);

short_desc = RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint " + HIY + "Light" + NORM + "house";
long_desc ="  The northwest room is a small bedroom covered in pink.\n"+
           "Tucked into a large mirror is a small aged photograph.  The\n"+
           "contents of the room have been scattered, as if someone was\n"+
           "searching for something.  The rumpled bed has a covering of\n"+
           "white chenille.  There is no evidence of human presence.\n";
items = ({
  "room","The small room is painted a pale pink.  A tiny window looks\n"+
         "out on the sea.  It appears abandoned",
  "mirror","The large wood framed mirror has a photograph tucked in the frame",
  "bed","The small white bed is covered with a flowered bedspread",
  "photograph","The photograph is of three beautiful children playing\n"+
                "together in a lake",

  });

dest_dir = ({
  "/players/softly/point/rooms/lh1.c","southeast",

  });
}

