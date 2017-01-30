inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The jungle");
  long_desc=
    "The jungle thins out a little here. The trees grow sparse\n"+
    " and you can see a small clearing off in the distance.\n"+
    "The ground begins to rumble in a rythmic fashion like someone\n"+
    "is marching. You here the trumpet of an elephant from\n"+
    " that same direction.\n";
  dest_dir=
({
      "/players/bagera/jungle/room37.c", "south",
      "/players/bagera/jungle/room21.c", "north",
      "/players/bagera/jungle/room28.c", "west",
      "/players/bagera/jungle/room30.c", "east"
});
 }
