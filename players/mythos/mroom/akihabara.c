inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Akihabara Station>> ";
    long_desc =
    "                    Akihabara Station\n\n"+
    "You are at a train station.  This place is teaming with teenagers\n"+
    "and business men- all looking into the high-tech world.  Akihabara\n"+
    "is the place where one goes for the cybertech and the electronics.\n";
  items = ({
    "narita","The airport to where eveywhere can be got to",
    "tokyo","The center of the city",
    "ikebukuro","The place of trade",
    "shinjuku","The teaming place of social life",
    "out","Out to the streets of akihabara",
  });

  dest_dir = ({
    "/players/mythos/mroom/narita.c","narita",
    "/players/mythos/mroom/tokyo.c","tokyo",
    "/players/mythos/mroom/ikebukuro.c","ikebukuro",
    "/players/mythos/mroom/shinjuku.c","shinjuku",
    "/players/mythos/mroom/akihabara1.c","out",
  });
} }
