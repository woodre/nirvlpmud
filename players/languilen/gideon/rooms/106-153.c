#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
inherit "room/room";


reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = "First Avenue at Short Street";
     long_desc =
"    This is an intersection of first avenue where it crosses\n\
short street.  The corner of a\n\
wharehouse makes a wall to the southeast.\n";

     items = ({
  "","",
});

     dest_dir = ({
        AREA+"107-153.c","north",
        AREA+"106-154.c","east",
        AREA+"105-153.c","south",
        AREA+"106-152.c","west",
});

}

