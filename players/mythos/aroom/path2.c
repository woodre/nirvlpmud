inherit "room/room";
reset(arg) {
  if(!present("messenger")) {
    move_object(clone_object("/players/mythos/amon/messenger.c"),this_object()); 
    move_object(clone_object("/players/mythos/amon/forest/pool.c"),"/players/mythos/aroom/forest/pool.c");}
  if(!arg) {
  set_light(1);
    short_desc = "Path";
    long_desc =
    "You trod along on the path.  The path branches off here.\n"+
    "To the south, you can make out a small hut.  To the east is\n"+
    "the village.  Along the path is a rice patty where the main\n"+
    "meal of the day is cultivated.  To the west is the portal.\n";
  items = ({
    "path","The path has been used a lot",
    "east","You make out a village to the east",
    "west","A blue shimmering light comes from the west",
    "south","You see a small hut to the south",
    "rice","The rice patties are in good shape.  Seems this year's crop is going to be good",
  });

  dest_dir = ({
    "/players/mythos/aroom/rice.c","north",
    "/players/mythos/aroom/path1.c", "west",
    "/players/mythos/aroom/phut.c","south",
    "/players/mythos/aroom/village.c","east",
  });
} }
