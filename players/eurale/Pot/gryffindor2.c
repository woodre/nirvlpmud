#include "DEF.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = HIR+"Gryffindor Commons"+NORM;
long_desc =
  "  Soft, comfortable chairs and sofas fill this spacious room.  Three large\n"+
  "tables provide space for studying.  A big fireplace takes up most of the\n"+
  "northern wall.  Covering the floor is a plush, soft carpet.  There are two\n"+
  "doorways off to the east and west that lead to the sleeping quarters.\n";

items = ({
  "chairs","Stuffed chairs with comfortable backs used for relaxing or studying",
  "sofas","Small, two person sofas that might be used for shared study or napping",
  "fireplace","Cut into the wall and burning with a "+HIR+"bright scarlet flame"+
              NORM+", this\n"+
              "massive fireplace heats the entire room",
  "wall","Made of stone like the rest of the castle",
  "carpet","A brown shag with an everchanging pattern",
  "pattern","Changing from squares to circles to stars repeatedly",
  "doorways","Narrow with a domed top, they lead to the male and female sleeping\n"+
             "rooms of the Gryffindor housemates",
});

dest_dir = ({
  "players/eurale/Pot/gryffindor.c","out",
  "players/eurale/Pot/gryffindor4.c","east",
  "players/eurale/Pot/gryffindor3.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
}

Search(str) {
if(!str) { write("You search aimlessly but to no avail.\n"); return 1; }
write("You search the "+str+" but find nothing special.\n");
say(capitalize(TPRN)+" searches the "+str+" but finds nothing.\n");
return 1;
}
