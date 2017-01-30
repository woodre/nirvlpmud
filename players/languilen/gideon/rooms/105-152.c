#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "Atrium";
     long_desc =
"    This room has a large circle cut from the cieling exposing the\n\
center of the room to the elements.  The very middle of the room is\n\
bare but beautifully tiled while the corners and walls are covered\n\
with various plant life.  It looks like the rental area is just to the\n\
west and an archway in the east wall leads out to the street.\n";

     items = ({
  "tile","Earthy brown tones in an unusual mosaic pattern",
});

     dest_dir = ({
        AREA+"105-153.c","east",
        AREA+"105-151.c","west",
});

}

