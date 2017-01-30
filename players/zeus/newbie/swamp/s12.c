inherit "room/room";  /*  12 */

reset(arg){
 if(!arg){

  short_desc="A muggy forest";
  long_desc=
"This is a narrow path leading through a forest.  The trees are growing\n"+
"quite close together, preventing movement off the path, which is going\n"+
"to the east and west.  You are very hot in this forest, the air almost\n"+
"feels thick as you breath it.  The sun can be seen through the trees,\n"+
"looming high above in the sky.\n";
  set_light(1);
  items=({
 "trees",
"The trees are a mix of cypress and mangrove.  They climb high into the\n"+
"sky, and make up most of the forest.  Some roots are visible at the base\n"+
"of the mangroves, protruding from the ground",
 "roots",
"Some gangly roots can be seen protruding from the ground around the bases\n"+
"of the mangrove trees",
 "path",
"The dirt path leading through the forest is clearly defined.  It is quite\n"+
"smooth, making travel rather easy",
 "sun",
"High above the golden sun can be seen through the trees.  It makes you\n"+
"feel as though a weight is pressing down on you",
 "sky",
"Patches of the beautiful blue sky can be seen through the trees",
  });
  dest_dir=({
	  "/players/zeus/newbie/swamp/s13.c", "east",
		  "/players/zeus/newbie/swamp/s11.c", "west",  });
} }
