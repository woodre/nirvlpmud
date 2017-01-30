#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Hills of Deacrom ";
    long_desc =
    "You step onto the top of a large grassy hill.\n"+
    "The sun beats down upon you and the air is sweet.\n"+
    "Below a river runs through a vast valley.\n";
  items = ({
    "down","Down the hill",
    "back","Goes back to the Chamber of Realms",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/hills2.c","down",
    "/players/mythos/enterance.c","back",
  });
} }
