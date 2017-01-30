#include "/players/jaraxle/ansi.h"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
object npc;

reset(arg) {
  if(!present("jacoby"))
    move_object(clone_object("/players/fred/closed/templar/jacoby.c"), this_object());
  if(arg) return;
set_light(1);

short_desc = HIW+"Jacoby's Chambers ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM;
long_desc =
"  A large chamber set deep within the castle. A window, draped with\n"+
"textured velvet curtains lets in minimal light, and a torch brings a\n"+
"warm, flickering glow to the room. An oak desk, polished smooth to\n"+
"the touch and a chair are near the western wall. There is a thickly\n"+
"woven rug covering much of the floor, and a map of the realm hung on\n"+
"the northern wall.\n";

items = ({
"map",
"The ancient map of the realm has many notes and pinpoints marked",
"rug",
"The rug is soft to the touch and deep red in color",
"desk",
"An oak desk, carved of solid wood and polished to a shine",
"chair",
"The chair is simple in design, but made for comfort",
"torch",
"An eternal torch, flickering softly",
"curtains",
"Deep, red velvet curtains, textured with an intricate floral pattern",
});

dest_dir = ({
  "/players/jaraxle/templar/rooms/hallway2","east",
});
}
