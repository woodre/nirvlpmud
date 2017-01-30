inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Ikebukuro Station>> ";
    long_desc =
    "                    Ikebukuro Station\n\n"+
    "This is a place where people come for interaction of different \n"+
    "lands and diversity of cultures.  The International Mall system\n"+
    "is located here as well as SunShine City.\n";
  items = ({
    "ginza","Head to the shopping area",
    "akihabara","The place for the future",
    "beyond","Step forward and go into the past....",
  });

  dest_dir = ({
    "/players/mythos/mroom/akihabara.c","akihabara",
    "/players/mythos/mroom/shinjuku.c","shinjuku",    
    "/players/mythos/mroom/grass.c", "beyond",
  });
} }
