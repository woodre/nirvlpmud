inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Ginza Station>> ";
    long_desc =
    "                    Ginza Station\n\n"+
    "You reach ginza station.  The station where one gets off to go\n"+
    "shopping, for ginza i s the shopping area of Tokyo. People swarm\n"+
    "through the station, as they trod upon the most expensive land in\n"+
    "the world....\n";
  items = ({
    "juliana","The hottest dance club there is",
    "tokyo","The center of everything",
    "out","Out to the streets of ginza",
    "roppongi","The place where things happen",
    "narita","The airport to everywhere",
  });

  dest_dir = ({
    "/players/mythos/mroom/juliana.c","juliana",
    "/players/mythos/mroom/tokyo.c","tokyo",
    "/players/mythos/mroom/roppongi.c","roppongi",
    "/players/mythos/mroom/narita.c","narita",
    "/players/mythos/mroom/ginza1.c","out",
  });
} }
