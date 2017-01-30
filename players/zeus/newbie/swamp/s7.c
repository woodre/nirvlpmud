inherit "room/room";  /* 7  */

reset(arg){

  if(!present("friendly hunter")){
	  move_object(clone_object(
		  "/players/zeus/newbie/NPC/f_hunter.c")); }

 if(!arg){

  short_desc="A muggy forest";
  long_desc=
"You are standing in a small clearing in the forest.  The path ends here,\n"+
"leading only back to the south.  Through the trees above the sun can be\n"+
"seen high in the sky.  A few ferns are growing around the bases of the\n"+
"trees.  The air is very hot and humid.\n";
  set_light(1);
  items=({
 "path",
"The dirt path is quite smooth and clearly defined here.  It leads to the\n"+
"south, back out of the clearing",
 "trees",
"The mangrove and cypress trees climb high into the sky.  They look as\n"+
"they have been here for centuries.  Some roots are visible at the bases\n"+
"of the mangrove trees",
 "roots",
"Some thin brown roots can be seen protruding from the ground around the\n"+
"bases of the mangrove trees",
 "sun",
"The beautiful sun can be seen through the trees above.  It is feeding the\n"+
"forest with energy",
 "sky",
"The sky is a beautiful blue, with not a cloud in sight",
 "ferns",
"Some leafy green ferns are growing around the bases of the trees here.\n"+
"They are very full, doing quite well in this warm climate",
  });
  dest_dir=({  "/players/zeus/newbie/swamp/s11.c", "south", });
} }
