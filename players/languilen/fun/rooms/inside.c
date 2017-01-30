#include "/players/languilen/closed/ansi.h"
#include "../paths.h"
#define TPN this_player()->query_name()
#define TP this_player()
#define STREET "/players/languilen/areas/city/rooms/103-150.c"
inherit "room/room";

object old_player;

reset(arg) {
     if(arg) return;
     set_light(1);

     short_desc = HIG+"Fun"+HIB+"house"+NORM+" Entrance";
     long_desc =
"    There are flashing lights, whistles and bells going off all over\n\
the place.  The black and white square tiles where the children run\n\
only serve to highten the sense of meyhem.  The beckoning neon lights\n\
of the snackbar flash to the north, while east is the way you came in.\n\
Set into the west wall is an enclosed slide leading to the hall of mirrors.\n";

     items = ({
     "lights","Strobes of all different colors flash from above",
     "tiles","The tiles are a checkered pattern and look a bit used but not warn",
     "slide","It's a chute that takes you to the hall of mirrors", 
     });

     dest_dir = ({
	AREA+"snackbar.c","north",
        AREA+"mirror.c","slide",
        AREA+"lobby.c","east",
   });
}

init(){
     ::init();
     add_action("listening","listen");
}

listening(){
     write("Shrill whistles and clamouring bells make hearing much else a chore.\n");
     return 1;
}

realm(){ return "NT"; }
