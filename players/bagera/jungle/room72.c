inherit "room/room";
int i;
reset(arg) {
if(!present("sheercon")) {
move_object(clone_object("/players/bagera/monster/sheercon.c"), this_object());
}
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The trees are thick here, but there is an opening through\n"+
    "the trees to the east. It is dark through the opening, but it\n"+
    "beckons you anyways. \n";
  dest_dir=
    ({
      "/players/bagera/jungle/room64.c", "north",
      "/players/bagera/jungle/room71.c", "west",
      "/players/bagera/jungle/room73.c", "east"
    });
  }
