#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("magenta")) {
 move_object(clone_object("/players/pestilence/blue/mob/magenta.c"),
        this_object()); }
short_desc = ""+CYN+"Before Blue's Clues"+NORM+"";
long_desc =
  "    This is a walkway that stretches out to the north leading to the\n"+
  "house of Blue and Steve.  On either side of the walk grows a carpet\n"+
  "of plush green grass.  Various toys are scattered about.  To the east\n"+
  "stands a large tree.\n";


set_light(1);

items = ({
  "house","A large yellow house with a red roof and a purple door, with two windows on the front",
  "toys","A few squeaky dog toys lay in the grass",
  "carpet","The grass is green and seems to be well taken care of",
  "walk","This is a gray cement sidewalk leading to the door of the house and back to the street",
  "walkway","This is a gray cement sidewalk leading to the door of the house and back to the street",
 "grass","The grass is green and seems to be well taken care of",
  "door","A large yellow door at the entrance of Blue and Steve's house",
  "tree","A large tree seems to be to the east of here",
});

dest_dir = ({
  "/players/pestilence/hall.c","back",
  "/players/pestilence/blue/rooms/tree.c","east",
  "/players/pestilence/blue/rooms/room1.c","north",
});
}
