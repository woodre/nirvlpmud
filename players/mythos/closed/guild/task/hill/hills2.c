#include "/players/mythos/closed/guild/def.h"
inherit "room/room";
reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Hills of Deacrom ";
    long_desc =
    "You venture down into depths of the hill.\n"+
    "Below you see a raging river...\n";
  items = ({
    "down","Down the hill",
    "up","Heads back",
  });

  dest_dir = ({
    "/players/mythos/closed/guild/task/hill/hillsr.c","down",
    "/players/mythos/closed/guild/task/hill/hills.c","up",
  });
} }
