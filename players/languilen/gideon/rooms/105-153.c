#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "First Avenue at the Carpet Factory";
     long_desc =
"    This is the southern end of first avenue where it dead ends\n\
into the mercantile flood that is the bazaar.  The corner of a\n\
wharehouse makes a wall to the east.  The stone wall to the west has\n\
an archway through it with a sign above it.\n";

     items = ({
  "sign","The sign is artisticly crafted and very colorful but not too easy to read",
});

     dest_dir = ({
        AREA+"106-153.c","north",
        AREA+"104-153.c","south",
        AREA+"105-152.c","west",
});

}

