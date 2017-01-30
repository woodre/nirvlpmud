#include "/players/softly/closed/define.h"
#include "/players/softly/point/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/vertebraker/closed/std/room";
int found;
reset(arg) {
  if(arg) return;

set_light(0);

short_desc=("Wrecked Vessel");
long_desc ="  The bow of the wrecked vessel is relatively\n\
intact, but the boards are thin and worn.  While the fittings\n\
are all absent, the shape of the vessel remains.  Something\n\
light colored lies in a pile of wood.\n";

items = ({
  "pile","Weathered boards have been tossed into a heap,\n"+
         "as if someone had been looking for something",
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
  "/players/softly/point/rooms/h1.c","south",
  });
}
void init()
{
    ::init();
  add_action("search", "search");
}

search(str){
if(!str) return;
if(found){ write("There is nothing there.  It may have\n"+
                 "been the pale sand beneath the wood.\n"); 
return 1; 
}

if(str == "wood"){
write("You found a pirate skull in the pile of wood.\n");
move_object(clone_object("/players/softly/point/obj/skull"), this_player());
found = 1;
return 1; 
} 
return; 
}
