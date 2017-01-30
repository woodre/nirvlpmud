inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/mmon/bustle.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "<<Entrance to Tokyo Tower>> ";
    long_desc =
    "                     Entrance to Tokyo Tower\n"+
    "Far above you stretches the Tokyo Tower- 666 meters tall.\n"+
    "It is a land mark of Tokyo, from where everything can be seen.\n";
  items = ({
    "roppongi","Head to the train station",
    "enter","Enter the high tower",
    "out","Back out to the streets of Roppongi",
  });

  dest_dir = ({
    "/players/mythos/mroom/ttower1.c","enter",
    "/players/mythos/mroom/roppongi1.c", "out",
     "/players/mythos/mroom/roppongi.c","roppongi",   
  });
} }
