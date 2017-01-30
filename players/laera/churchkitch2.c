#include "/players/softly/closed/define.h"
#include "/players/softly/closed/ansi.h"
inherit "/players/laera/cforest/hroom.c";

reset(arg){
if(!present("chlady1"))
    move_object(clone_object("players/softly/algiers/mobs/chlady1.c"),this_object());
if(!present("chlady2"))
    move_object(clone_object("players/softly/algiers/mobs/chlady2.c"),this_object());
  if(arg) return;
  set_light(1);

  short_desc = "Fellowship Church Kitchen";
  long_desc ="\n"+
    "  A bright open kitchen painted in thick layers of white paint\n"+
    "has a large stove, several sinks, and a two huge refrigerators.\n"+
    "In the center is a wooden island of sturdy wood covered with flour,\n"+
    "chickens, and unmatched cookware.  The brown tiled floor is very worn.\n";

  items = ({
    "wood",
    "The island is made of wood.  On the top is a\n\
thick cutting surface",
    "parts",
    "Legs, breasts, wings, and thighs cut from chickens",
    "bag",
    "A brown paper bag filled with flour for dredging\n\
chicken before cooking",
    "plates",
    "Thick white plates are covered with as yet\n\
uncooked chicken parts",
    "pans",
    "Large iron frying pans hold half cooked chicken\n\
Baking pans hold biscuits",
    "pot",
    "An old sauce pan with two handles.  It is small",
    "board",
    "A ridged metal surface next to one of the sinks",
    "sinks",
    "Stainless steel sinks that can hold a large amount",
    "door",
    "A small white swinging door sits unobtrusively on the west side",
    "stove",
    "An ancient iron stove dominates one side of the room",
    "sinks",
    "Two sinks stand side by side with a large white drain board to the left",
    "refrigerators",
    "Two immense refrigerators, clean but aged, stand next to the sinks",
    "island",
    "The island, large enough to allow six workers, is topped with a\n"+
    "heavy wooden surface to allow cutting",
    "flour",
    "The white powder spills out of a brown paper bag",
    "chickens",
    "Several whole chickens and uncounted chicken parts lie on large plates",
    "cookware",
    "Several frying pans, a small pot, and several biscuit pans are on the counter",
    "floor",
    "Multi-hued brown tiles cover the floor, worn but very clean",  

  });

  dest_dir = ({
    "/players/softly/algiers/rooms/churchmain.c","west",
  });
}
