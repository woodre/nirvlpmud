inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Caemlyn Wilderness";
long_desc =
"   Thick bushes line the narrow path, and a few tall maple trees\n"+
"wave in the slight breeze above.  The bushes are thick with thorns,\n"+
"and force you to stay on the path.\n";

items = ({
"bushes",      "Mostly dense and thick brush, with sharp thorns...",
"path",        "A well worn dirt path which it seems you must follow",
"trees",       "Tall white maple trees, waving in the breeze",
});

dest_dir = ({
   "/players/fakir/caemlyn/room4.c", "northeast",
   "/players/fakir/caemlyn/room2.c", "south",
});
}


