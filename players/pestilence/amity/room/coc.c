#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+HIB+"Chamber of Commerce"+NORM+"";
long_desc =
  "    This is the Chamber of Commerce.  There is a gray carpet that\n"+
  "extends from wall to wall.  The walls are painted a light blue.  This\n"+
  "is the place all the businesses of Amity get together and decide on\n"+
  "village policies.  There are a couple of desks here, and a large\n"+
  "meeting table on the south wall of the room.  On the north wall there\n"+
  "is a portrait of the town mayor with two American flags on each side\n"+
  "of him.\n";
set_light(1);

items = ({
"desks","Large wooden desks lined against the north wall",
"table","A large wooden table with several chairs around it sits agaisnt the south wall",
"flags","Two American flags on each side of the mayor in the portrait",
"mayor","An older man with gray hair and a gray moustache wearing a suit",
"floor","Gray carpet extending from wall to wall",
"carpet","Gray carpet extending from wall to wall",
"portrait","A picture of the mayor standing outside the Chamber of Commerce",
"wall","The wall is painted a light blue", 
"walls","The walls are all covered with light blue paint",
"chairs","Wooden chairs used to sit on during meetings",
});

dest_dir = ({
"/players/pestilence/amity/room/nmain1.c","west",
});
}
