#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(3);
    short_desc = "Valley of Deacrom ";
    long_desc =
    "You find yourseelf at the bottom of the hill, the\n"+
    "valley stretches out in front of you.  The river\n"+
    "roars as it rushes by as the sun beats down on you.\n";
  items = ({
    "river","You may reach the river",
    "up","Up the hill",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hills/hills2.c", "up",
    "/players/mythos/closed/guild/task/hills/river.c","river",
  });
} }
