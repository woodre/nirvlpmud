inherit "room/room";
reset(arg) {
if(!arg) {
  set_light(0);
    short_desc = ">>>>>><<<<<<";
    long_desc =
    "You are in a small room....\n";

  dest_dir = ({
    "/players/mythos/closed/guild/task/1/1.c", "north",
    "/players/mythos/closed/guild/task/1/6.c", "south",
    "/players/mythos/closed/guild/task/1/1.c", "east",
    "/players/mythos/closed/guild/task/1/6.c", "west",
  });
} }
