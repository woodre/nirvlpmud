  inherit "room/room";
  reset(arg){
   if(!present("fahkri")) {
 move_object(clone_object("/players/arrina/tmon/fahkri.c"),this_object());
 }
    if(!arg){
    set_light(0);
    short_desc="Tunnel Entrance";
   long_desc=
  "You enter the narrow tunnel from the back of the hunting pit.  The\n" +
  "earth seems to close in around you.  The walls are too close, the\n" +
  "ceiling is too low.  The whole place is damp and rank, and smells\n" +
  "of decay.  You realize you have entered the home of the Qurds, a\n" +
  "race reported to be half animal and half human.  As you peer \n" +
  "deeper into the tunnel, it appears that natural caverns merge \n" +
  "with tunnels carved out by the Qurds to form a labyrinth. You \n" +
  "sense movement and life within the tunnel.\n";
    items=({
   "ceiling", "Occasionally water drips from the ceiling, and it is\n"+
           "low enough that you can't stand upright in all places",
   "walls","The walls are covered in slime and mildew",
  });
    dest_dir=({
  "/players/arrina/grounds/hunttrap.c","back",
  "/players/arrina/tunnel/tunnel2.c","north",
   });
 }
 }
realm() { return "NT"; }

init() {
  ::init();
  add_action("go_back","back");
}

go_back() {
  call_other("/players/arrina/grounds/hunttrap.c","toggle_hurt");
  this_player()->move_player("back#players/arrina/grounds/hunttrap.c");
  return 1; }
