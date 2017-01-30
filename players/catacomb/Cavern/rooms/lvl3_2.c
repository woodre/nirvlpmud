inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc =("Deep within the Durkor Caverns");
long_desc =(
"  Moisture drips off the ceiling fresh from a Durkor lizard rider's kill.\n"+
"The blood dripping from the ceiling falls into a now small pool below.  The\n"+
"lizard riders are the most feared of the Durkor.  The lizards chosen for \n"+
"the riders are trained in only destruction, attacking anything close except\n"+
"for the rider.\n"); 

if(!present("warrior"))
	  move_object(clone_object("/players/catacomb/Cavern/mobs/Dwarrior.c"),
	    this_object());

items = ({
  "moisture",
  "The moisture appears to be the blood of some unfortunate creature", 
  "blood",
  "Blood drips from the ceiling and forms a pool on the cavern floor",
  "pool",
  "A small pool of blood from the lizard rider's latest victim",
  "ceiling",
  "As you look at the ceiling some blood drips on your face",
  "floor",
  "On the floor of the cave there is a small pool of blood" 
});

dest_dir = ({
  "/players/catacomb/Cavern/rooms/lvl3_1.c","southeast",
  "/players/catacomb/Cavern/rooms/lvl3_3.c","south", 
  });
}

