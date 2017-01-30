#include "/players/softly/closed/ansi.h"

inherit "/room/room";

reset(arg) {
  if(!present("bryant")) 
  move_object(clone_object("players/softly/point/mobs/mbryant"),this_object());
  if(arg) return;

set_light(1);

short_desc = RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint " + HIY + "Light" + NORM + "house";
long_desc ="  The northeast room seems to be the bedroom of the couple\n"+
           "who keep the lighthouse.  The small window overlooks the\n"+
           "sea.  The double bed is covered with a hand made quilt of\n"+
           "many colors and fabrics.  Two dressers have been thrown\n"+
           "open, their contents scattered.  A small rug is pushed\n"+
           "against the far wall.  A wall mirror is askew.\n";

items = ({
  "room","The small room has pale blue and white striped wallpaper",
  "bedroom","A double bed dominates the room",
  "window","Rough seas are visible through the uncovered window",
  "bed","The large high bed is neatly made",
  "quilt","A patchwork quilt has been lovingly made from scraps",
  "dressers","A high and a low dresser are painted white",
  "rug","The had braided rug seems to have been pushed aside\n"+
        "by someone in a hurry",
  "mirror","A wood-framed mirror above the low dresser seems\n"+
           "to have been bumped into.  It sits at an odd angle",
  });

dest_dir = ({
  "/players/softly/point/rooms/lh1.c","southwest",

  });
}

