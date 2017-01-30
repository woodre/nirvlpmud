inherit "room/room";
reset(arg) {
  if(!present("warrior")) {
    move_object(clone_object("/players/mythos/amon/forest/yoshitsune.c"),this_object()); }
  if(!arg) {
  set_light(0);
  short_desc = "Bridge";
    long_desc =
    "You pass beyond the trees and you come upon a bridge.\n"+
    "It spans over a raging river- 30 meters below.\n"+
    "It is hard to make out much in this dark forest.\n";
  items = ({
    "south","You can pass the trees and go back to the path",
    "cross","You see that the bridge continues...you see a figure in the darkness",
    "bridge","The bridge is made of sturdy wood.  \nSomething catches your eyes in the 'shadows'",
    "shadows","You notice a figure standing in the shadows of the trees- \nhe is a 'warrior'",
    "around","You see a way around the bridge toward the tower- a rope",
  });

  dest_dir = ({
    "/players/mythos/aroom/forest/pathway4.c", "south",
    "/players/mythos/aroom/forest/bridge2.c","cross",
    "/players/mythos/aroom/forest/around.c","around",
  });
} }
