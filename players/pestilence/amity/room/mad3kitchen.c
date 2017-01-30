#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";
int SEARCH;

reset(arg) {
SEARCH = 0;
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+BLU+"Kitchen"+NORM+"";
long_desc =
  "    This is the kitchen of the house.  There is part of a kitchen\n"+
  "table in the middle of the floor.  There is a stove on the west wall,\n"+
  "with counter top extending to the north and south.  A large white\n"+
  "refrigerator sits against the south wall, with a dishwasher next to\n"+
  "it.\n";
set_light(1);

items = ({
"table","A broken wooden table lays on the floor",
"stove","A beige electric stove on the west wall",
"counter","A beige counter going on the west wall extending on each side of the stove",
"counter top","A beige counter going on the west wall extending on each side of the stove",
"dishwasher","A beige dishwasher sits on the south wall, next to the refrigerator",
"refrigerator","A large beige refrigerator with side by side doors",


});

dest_dir = ({
  "/players/pestilence/amity/room/madhouse3.c","east",
});
}
