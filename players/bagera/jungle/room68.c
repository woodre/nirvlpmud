inherit "room/room";
reset(arg) {
if(!present("mogley")) {
move_object(clone_object("/players/bagera/monster/mogly.c"), this_object());
 }
if(!arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "This is the edge of the jungle. You can see only\n"+
    "an abyss towards the south. Tothe west the jungle\n"+
    "thins and becomes barren. To the east and north the\n"+
    "jungle grows thick.\n";
  dest_dir=
    ({
      "/players/bagera/jungle/room60.c", "north",
       "/players/bagera/jungle/room67.c", "west",
      "/players/bagera/jungle/room69.c", "east"
    });
 }
}
