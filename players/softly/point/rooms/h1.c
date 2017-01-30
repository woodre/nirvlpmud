#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";
int found;
reset(arg) {
  if(arg) return;

set_light(0);

short_desc=("Wrecked Vessel");
long_desc ="  The interior of the wrecked vessel is rotted from\n\
the effects of the sea and the ravages of time.  Holes dot the\n\
deck, most of the fittings have been removed, and rotting boards\n\
are everywhere.  The glint of something shiny can be seen through\n\
a crack between the boards of the deck.\n";

items = ({
  "vessel", "The vessel has been here a long time.  It is merely\n\
a shell with little remaining to remind you that\n\
it was once a majestic sailing ship",
  "sea","The sea has taken its toll on the hull of the ship",
  "time","Time has not been kind to this once majestic vessel",
  "holes","Many of the boards that once were the deck of the\n\
of the ship have rotted through",
  "fittings","There are lighter patches on the ship's wheel and other\n\
boards that once must have been covered with brass",
  "boards","This was a wooden ship, the deck and hull crafted\n\
by hand in a bygone era",
  "crack","Over time the boards have separated leaving wide\n\
spaces between them",

  });
dest_dir = ({
  "/players/softly/point/rooms/pt7.c","leave",
  "/players/softly/point/rooms/h2.c","bow",
  "/players/softly/point/rooms/h3.c","stern",
  });
}
void init()
{
    ::init();
  add_action("search", "search");
}

search(str){
if(!str) return;
if(found){ write("There is nothing in the crack.  Perhaps\n"+
                 "it was a reflection on the water beneath.\n"); 
return 1; 
}

if(str == "crack"){
write("You found a gold nugget in the crack!\n");
move_object(clone_object("/players/softly/point/obj/nugget"), this_player());
found = 1;
return 1; 
} 
return; 
}
