#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(2);
    short_desc = "Hills of Deacrom ";
    long_desc =
    "You descend to the middle of the hill.\n"+
    "The grass seems greener than before.\n"+
    "Ther is a cave to the east and the valley\n"+
    "stretches below.\n";
  items = ({
    "enter","You may enter the cave",
    "down","You may descend to the bottom of the valley",
    "up","Up the hill",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/hills.c", "up",
    "/players/mythos/closed/guild/task/hills/hills3.c","down",
    "/players/mythos/closed/guild/task/hills/cave.c","enter",
  });
} }
