#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!present("dragon")) {
  move_object(clone_object("/players/mythos/closed/guild/task/hill/dragon.c"),
  this_object());}
  if(!arg) {
  set_light(1);
    short_desc = "WhiteStone ";
    long_desc =
    "You stand before a great river....\n"+
    "In the middle of the rushing flow of water is\n"+
    "a great White Slab of Stone.  On it sits a \n"+
    "dragon of enourmous size!\n\n"+
    "In each compass direction is a shimmering portal...\n";

  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/hillsr2.c","back",
    "/players/mythos/closed/guild/task/hill/stones.c","north",
    "/players/mythos/closed/guild/task/hill/stones2.c","northeast",
    "/players/mythos/closed/guild/task/hill/stones3.c","east",
    "/players/mythos/closed/guild/task/hill/stones4.c","southeast",
    "/players/mythos/closed/guild/task/hill/stones5.c","south",
    "/players/mythos/closed/guild/task/hill/stones6.c","southwest",
    "/players/mythos/closed/guild/task/hill/stones7.c","west",
    "/players/mythos/closed/guild/task/hill/stones8.c","northwest",
  });
} }

realm() { return "NT"; }
