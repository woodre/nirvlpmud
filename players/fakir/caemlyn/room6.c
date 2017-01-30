inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Caemlyn Wilderness";
long_desc =
"   Bushes line the narrow path in places, and thick maple trees wave\n"+
"in the slight breeze above.  Tall blooming flowers mix with the green\n"+
"leaves of the bushes and create a colorful palette of natures beauty.\n";

items = ({
"leaves",      "Green lace leaves with just a touch of autum color",
"flowers",     "Red, yellow, pink, and dark purple blooms on tall stalks",
"bushes",      "Mostly dense and thick brush, with sharp thorns...",
"path",        "A well worn dirt path which it seems you must follow",
"trees",       "Tall white maple trees, waving in the breeze",
});

dest_dir = ({
   "/players/fakir/caemlyn/room6.c", "south",
   "/players/fakir/caemlyn/room4.c", "southwest",
});
}


