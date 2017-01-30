inherit "room/room";
reset(arg) {
  if(!present("woman")) {
    move_object(clone_object("/players/mythos/closed/guild/task/1/woman.c"),this_object());} 
  if(!arg) {
  set_light(0);
    short_desc = ">>>>>><<<<<<";
    long_desc =
    "You are in a small room....\n"+
    "At the center is a terrified woman....\n";

  dest_dir = ({
    "/players/mythos/closed/guild/task/1/2.c", "north",
    "/players/mythos/closed/guild/task/1/3.c", "south",
    "/players/mythos/closed/guild/task/1/4.c", "east",
    "/players/mythos/closed/guild/task/1/5.c", "west",
  });
} }
