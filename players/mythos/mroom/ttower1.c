inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Tokyo Tower- First Floor>> ";
    long_desc =
    "                    First Floor <Tokyo Tower>\n"+
    "A vast room stretches out around you.  Ticket booths are here\n"+
    "selling the tickets to enter and see this tourist trap.  But\n"+
    "no need to buy a ticket today, you have a special pass....\n";
  items = ({
    "out","Back out to the world",
    "up","Up and up....",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower.c","out",
    "/players/mythos/mroom/ttower2.c","up",
  });
} }
