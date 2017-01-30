inherit "room/room";  /* 10  */

reset(arg){

  if(!present("friendly hunter") && !random(4)){
	  move_object(clone_object(
		  "/players/zeus/newbie/NPC/bandit.c")); }

 if(!arg){

  short_desc="A muggy forest";
  long_desc=
"The path leading through the forest is rather narrow here, and very\n"+
"clearly defined, as though it is traveled often.  The towering trees\n"+
"rise up all around you, although you can still see the golden sun\n"+
"high in the sky.  There isn't a cloud to be seen in the blue sky.\n";
  set_light(1);
  items=({
 "path",
"The dirt path is very smooth and clearly defined.  It leads to the east\n"+
"and west from where you stand",
 "trees",
"The old trees are all around you, towering high into the sky.  They are\n"+
"a mix of cypress and mangrove trees",
 "sun",
"The beautiful sun beating down on you, making you extremely hot.  Even\n"+
"though the path is very shady, there is no place to get away from the\n"+
"humid air",
 "cloud",
"There are no clouds to be seen in the sky",
 "sky",
"The soft blue sky is devoid of clouds",
  });
  dest_dir=({
	  "/players/zeus/newbie/swamp/s11.c", "east",
		  "/players/zeus/newbie/swamp/s9.c", "west", });
} }

