inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(0);
  short_desc = "Rope Crossing";
    long_desc =
    "You hang above the raging river with your hands holding\n"+
    "tightly to the rope.  You hope the rope holds.\n"+
     "Before you you see the Tower.\n";
  items = ({
     "around","You see the Tower looming above you",
    "back","The rope leads back to the bridge",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/tower.c","around",
    "/players/mythos/aroom/forest/bridge.c","back",
  });
} }

init() { ::init();
add_action("check","around");
add_action("check","back"); }

check() {
  if(!random(this_player()->query_attrib("ste")/4)) {
   write("\n\n");
    write("You slip...\n\t\tYou Fall....\n\n");
    this_player()->hit_player(random(100));
   write("You take some damage....\n");
write("\nYou scramble back onto the Rope Crossing....\n\n");  
  return 1; } }
