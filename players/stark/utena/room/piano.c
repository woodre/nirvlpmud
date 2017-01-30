inherit "/players/stark/room";
#include "/players/stark/defs.h"
reset(arg){

if(!present("miki"))  {
MOCO("/players/stark/utena/mon/miki.c"),this_object());  }
if(!present("kozue"))  {
MOCO("/players/stark/utena/mon/kozue.c"),this_object());  }

    if(arg) return;
    set_light(1);
    set_listen("Someone is playing the piano with precision and beauty.");
    set_smell("The perfume of a single woman resides in this room.");
    set_search("Outside of the piano, this room is bare.");
    short_desc="Ohtori Academy Music Hall";
    long_desc=
"   A large hall, not exactly designed for acoustics.  There is only \n"+
"one piano that occupies the room.  A large window casts light onto the \n"+
"piano.  This is usually the scene of beautiful music; be it from the \n"+
"strings, or from a couple using the empty room.\n";

items=({
"hall","This is the main Music Hall",
"piano","A closely tuned instrument of music",
"window","The piano stands out in a shower of light from this window"
});

dest_dir=({
"/players/stark/utena/room/cafe.c", "east"
});

}
