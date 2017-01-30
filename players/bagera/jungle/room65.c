inherit "room/room";
int i;
reset(arg) {
if(!present("vulture")) {
move_object(clone_object("/players/bagera/monster/vulture.c"), this_object());
}
if(!present("vulture1")) {
move_object(clone_object("/players/bagera/monster/vulture1.c"), this_object());
}
if(!present("vulture2")) {
move_object(clone_object("/players/bagera/monster/vulture2.c"), this_object());
 }
  set_light(1);
  short_desc=("Barren lands");
long_desc=(
    "The land is barren and dry. The trees are sparse and\n"+
    "bare. They look as if they have been scortched in a\n"+
    "fire and are black with soot. Perched on one of the\n"+
    "thicker branches are three vultures. They are perched\n"+
    "high above and over look the land. They look kind of\n"+
    "strange. You notice that one of them has a hair cut like\n"+
    "Ringo Starr and they all have english accents. They bounce\n"+
"about on their perch squaking and talking.\n");
  dest_dir=
   ({
      "/players/bagera/jungle/room57.c", "north",
      "/players/bagera/jungle/room66.c", "east",
      "/players/bagera/jungle/room58.c", "northeast"
  });
 }
