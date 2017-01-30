inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- Third Floor>> ";
    long_desc =
    "                      Third Floor <Tokyo Tower>\n"+
    "This is a small shopping center.  People bustle around looking for\n"+
    "trinkets and other what-nots to bring back home.  The people all\n"+
    "seem friendly and happy...\n";
  items = ({
    "up","Up and up....",
    "down","Down and Down.....",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower2.c","down",
    "/players/mythos/mroom/ttower4.c","up",
  });
} }
