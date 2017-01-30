inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Grass Area>> ";
    long_desc =
    "You have entered a small peaceful grass land.  You can go\n"+
    "back to the modern bustle of japan/tokyo, or you can head\n"+
    "to an older land of myth- the Empire.\n";
  items = ({
    "ikebukuro","Back to the station of modern japan",
    "portal","A portal into ancient japan....",
  });

  dest_dir = ({
    "/players/mythos/mroom/ikebukuro.c","ikebukuro",
    "/players/mythos/aroom/path1.c","portal",    
  });
} }
