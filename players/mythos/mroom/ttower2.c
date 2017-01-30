inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- Second Floor>> ";
    long_desc =
    "                      Second Floor <Tokyo Tower>\n"+
    "Here are games galour!  Children rush around as they play on\n"+
    "one video game then another.  People are chatting and relaxing\n"+
    "here.\n";
  items = ({
    "up","Up and up...",
    "down","Down and down....",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower1.c","down",
    "/players/mythos/mroom/ttower3.c","up",
  });
} }
