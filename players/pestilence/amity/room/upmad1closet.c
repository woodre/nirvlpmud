#include "/open/ansi.h"
#define TP this_player()
inherit "room/room";

reset(arg) {
  if(arg) return;

if (!present("mary")) {
  move_object(clone_object("/players/pestilence/amity/mob/maryd.c"),
        this_object()); }

if (!present("austin")) {
  move_object(clone_object("/players/pestilence/amity/mob/austin.c"),
        this_object()); }

if (!present("andrew")) {
  move_object(clone_object("/players/pestilence/amity/mob/andrew.c"),
        this_object()); }

short_desc = ""+BLU+"Small Closet"+NORM+"";
long_desc =
  "    This closet is very compact.  There are clothes hanging from\n"+
  "the hangers and shoes lined up on the floor.  There is red carpet\n"+
  "in the closet that extends back out to the bedroom.  The walls are\n"+
  "covered with a white paint.\n";
set_light(0);

items = ({
"closet","A very small closet",
"shoes","They are mostly women's shoes, with a few men's shoes",
"clothes","A few dresses and long shirts hang from the hangers",
"carpet","A red carpet extends from wall to wall",
"bedroom","You stick your head out the door and see a bedroom, a bed, red carpet and two dressers",
});

dest_dir = ({
  "/players/pestilence/amity/room/upmad3.c","out",
});
}
