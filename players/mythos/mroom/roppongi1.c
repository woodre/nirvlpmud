inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!present("seller")) {
    move_object(clone_object("/players/mythos/mmisc/drugs/seller.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Roppongi>> ";
    long_desc =
    "                     Roppongi\n"+
    "People rush around you.  Prostitutes call from the street corners,\n"+
    "street vendors hawk their products, and music mixes in the air\n"+
    "creating confusion.\n";
  items = ({
    "tower","The Tall Tokyo Tower stands before you",
    "in","Go back into the train station",
  });

  dest_dir = ({
    "/players/mythos/mroom/roppongi.c", "in",    
    "/players/mythos/mroom/ttower.c","tower",
  });
} }
