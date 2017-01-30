inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle2.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<The Quad- Common Room>> ";
    long_desc =
    "\n";
  items = ({
    "andrew","",
    "chris","",
    "john","",
    "masumi","",
  });

  dest_dir = ({
    "/players/mythos/mroom/andrew.c", "andrew",
    "/players/mythos/mroom/chris.c","chris",
    "/players/mythos/mroom/john.c","john",
    "/players/mythos/mroom/masumi.c","masumi",
  });
} }
