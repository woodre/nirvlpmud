#include "/open/ansi.h"
#define TP this_player()
inherit "/players/vertebraker/closed/std/room";

reset(arg) {
  if(arg) return;

if (!present("ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/armyant.c"),
        this_object()); }

short_desc = ""+BLU+"Madison Street"+NORM+"";
long_desc =
  "    The street here is near the very top of the hill.  The street\n"+
  "continues to the east, but there is a tree blocking the roadway.\n"+
  "There is a small path between two houses to the north leading to a\n"+
  "large mound of dirt.  The path is worn from things being dragged upon\n"+
  "it.  There is a large house to the south of Madison Street.\n";
set_light(1);

items = ({
"street","A well paved street with curbs on each side and a tree blocking it to the north",
"curbs","Cement curbs that run the length of the street",
"dirt","A large mound of brown dir to the north",
"hill","A hill inwhich the street ascends",
"tree","A large maple tree laying across the street",
"house","A large white house with the doors broken down",
"doors","The doors lay shattered on the ground",
"large house","A large white house with the doors broken down",
"mound","A mound of dirt, you can't quite make out the details",
"houses","A couple of white houses on each side of the street",
"path","A worn path leading to the west, in between two houses",
});

dest_dir = ({
  "/players/pestilence/amity/room/madison1.c","west",
  "/players/pestilence/amity/room/madhouse3.c","south",
  /* pointed this to void so players can still look in a 
      particular dir -verte */
  "/room/void", "east",
  "/players/pestilence/amity/room/path.c","north",
});
}
init() {
  ::init();
add_action("east","east");
}

east() {
write("You can't get past the tree, to go east any further.\n");
return 1; }
