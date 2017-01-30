inherit "room/room";    /* 11  */

reset(arg){
 if(!arg){

  short_desc="A muggy forest";
  long_desc=
"The path through the forest widens here, and breaks off in a number\n"+
"of different directions.  While the main path still seems to continue\n"+
"to the east and west, it also deviates to the north, and downhill to\n"+
"the southwest.  The air is incredibly humid.  The tall trees, which\n"+
"comprise most of the forest, tower high above your head.\n";
  set_light(1);
  items=({
 "path",
"The dirt path is smooth and easy to walk on.  There are a few visible\n"+
"roots, but they are rather small.  The path leads away from this point\n"+
"in four different directions",
 "trees",
"There are two kinds of trees here, cypress and mangrove.  They are all\n"+
"around you, and are blocking out a lot of the sky",
 "sky",
"Pieces of the soft blue sky can be seen through the trees",
 "roots",
"A few roots are visible in the path, as well as right near the bases\n"+
"of some of the trees in the forest",
  });
  dest_dir=({
	"/players/zeus/newbie/swamp/s7.c", "north",
	"/players/zeus/newbie/swamp/s12.c", "east",
	"/players/zeus/newbie/swamp/s10.c", "west",
	"/players/zeus/newbie/swamp/s15.c", "southwest", });
} }
