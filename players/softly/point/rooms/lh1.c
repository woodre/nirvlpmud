#include "/players/softly/closed/ansi.h"

inherit "/room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = RED + "R" + NORM + "ocky " + RED + "P" + NORM + "oint " + HIY + "Light" + NORM + "house";
long_desc ="  The front room of the living quarters a small room that\n"+
           "was well cared for.  The worn furnishings are comfortable.\n"+
           "Lace curtains cover the windows and a few books about the\n"+
           "sea lie on a table.  Doors to the northwest, northeast and\n"+
           "east are open.\n";

items = ({
  "room","The small room is covered in light wood paneling.  Two\n"+
         "windows brighten it.  It appears abandoned",
  "furnishings","A sofa and two chairs are covered with green flowered\n"+
                "fabric.  A small wooden table sits in the center of the\n"+
                "room.  Two brass lamps sit atop tiny tables under the\n"+
                "windows.  A collection of shells rest near the lamps",
  "curtains","Light clean lace curtains float over the windows",
  "books","'Navigation Rules', 'Tide Tables 1988', and 'Ships\n"+
          "and the Sea'",
  "doors","The white doors to the northeast, northwest and east\n"+
          "are slightly open",
  "windows","Two small windows with once white curtains\n"+
            "overlook the sea",
  "sofa","The sofa which has three cushions is covered in\n"+
         "a green flowered fabric.  It looks worn",
  "chairs","Two upholstered chairs sit facing the sofa.\n"+
           "They are covered in the same green flowered fabric",
  "table","The rustic low table sits between the sofa and\n"+
          "and the two chairs.  Several books are on it",
  "lamps","The brass lamps have off white shades.  They\n"+
          "once provided light to read by",
  "tables","Two small tables are under the windows.  Each\n"+
           "table holds a brass lamp and a collection of\n"+
           "shells",
  "shells","Scallop, whelk, conch, cowrie, and clam shells\n"+
           "are collected in a casual arrangement",
  });


dest_dir = ({
  "/players/softly/point/rooms/lh2.c","east",
  "/players/softly/point/rooms/lh3.c","northwest",
  "/players/softly/point/rooms/lh4.c","northeast",
  "/players/softly/point/rooms/pt5.c","exit",
  });
}

