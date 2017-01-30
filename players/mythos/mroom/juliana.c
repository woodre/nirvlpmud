#include "/players/mythos/closed/ansi.h"
inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Entrance to Juliana's Tokyo>> ";
    long_desc =
    RED+BLINK+"                    JULIANA'S TOKYO\n\n"+NORM+
              "You are at the place where "+HIR+"HOT"+NORM+" music and people meet.\n"+
              "This is the place where dance is up and life is fast.  The rave\n"+
              "scene of Tokyo!\n";
  items = ({
    "enter","Step into the world of music and dance",
    "narita","Head to the airport",
    "ginza","Go to the station where life is full of shopping",
    "roppongi","Go where everyone who is who is",
    "east","Take a stroll",
  });

  dest_dir = ({
  "/players/mythos/mroom/juliana1.c","enter",
    "/players/mythos/mroom/ginza.c","ginza",
    "/players/mythos/mroom/narita.c","narita",
    "/players/mythos/mroom/roppongi.c","roppongi",
    "/players/mythos/mroom/juliana0.c","east",
  });
} }
