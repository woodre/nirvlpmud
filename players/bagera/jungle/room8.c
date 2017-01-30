inherit "room/room";
reset(arg) {
  set_light(1);
  short_desc=("The end of a ravine");
  long_desc=
    "The ravine gently curves tothe south here. The jungle\n"+
    "lies ahead, trees looming above. To get to civilization\n"+
    "you must venture through the jungle. The brush is thick\n"+
    "and the trees are dense. Beware of the wild animals of the \n"+
"jungle.\n";
  dest_dir=
({
    "/players/bagera/jungle/room16.c", "south",
    "/players/bagera/jungle/room7.c", "west"
   });
  }
