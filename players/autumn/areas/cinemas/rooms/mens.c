inherit "/room/room";
#include "/players/autumn/defs.h"


/*TO DO'S: 
* Fix checkPlayer() & message placement
* 
*/

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(CYN+"A Men's Restroom"+NORM);

long_desc=
 
HIK+"The Men's restroom:\n"+NORM+YEL+
"The room's walls are a variety of browns with rigidly textured.  The floor is tiled\n"+
"with lightly shaded cobblestones. The counter extends the length of the room and is\n"+
"plain looking.  Urinals line the wall and there are two, silver stalls in the\n"+
"back of the room.  The room is very crowded, yet quiet.\n"+NORM+HIK;  



items = ({
  "walls","Brown, righty walls; they almost look carpeted.",
  "floor","The floor is tiled with lightly shaded cobblestones, of green, white, brown, & peach",
  "stalls","Silver bathroom stalls; they are empty.",
  "counter","An off-white, granite counter",
  "sink","Ordinary, white, circular sinks.",
  "room","A bathroom full of men"



});

dest_dir = ({
  "/players/autumn/cinemas/rooms/lobby.c","out",

});



}

init()
{
 
  ::init();
  add_action("search","search");
  add_action("smell","smell");
  add_action("listen","listen");
  
}



search()
{
	write("There is nothing to search here!\n"); 
	say(TPN+" is looking around.\n");
	return 1;
}

smell()
{
	write("The room reeks of cigarettes and urine.\n");
	return 1;
}

listen()
{
	write("It's oddly quiet.\n");
	return 1;
}

