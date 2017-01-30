inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); }
  if(!present("go player")) {
     move_object(clone_object("/obj/go_player.c"),this_object()); }
  if(!present("kama")) {
    move_object(clone_object("/players/mythos/awep/kama.c"),this_object()); }
  if(!arg) {
  set_light(1);
    short_desc = "Shade";
    long_desc =
    "You reach the end of the path.  Before you is a small hut.\n"+
    "Outside of the hut, sitiing under the shade of a tree, is a\n"+
    "farmer (Go player) who is taking a break from the hard work\n"+
    "of tending the rice fields.\n";
  items = ({
    "hut","The hut is a small roundish looking building",
    "north","You see the junction of the path",
    "path","The path has been used a lot",
    "tree","A tall tree whose shade seems rather cool",
  });

  dest_dir = ({
    "/players/mythos/aroom/path2.c", "north",
    "/players/mythos/aroom/hut.c","hut",
  });
} }

