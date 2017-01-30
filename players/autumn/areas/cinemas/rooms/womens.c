inherit "/room/room";
#include "/players/autumn/defs.h"


/*TO DO'S: 
* Fix checkPlayer() & message placement
* 
*/

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(HIW+"A Women's Restroom"+NORM);

long_desc=
 
HIK+"The Women's restroom:\n"+NORM+YEL+
"The walls are lined with a silver wallpaper embossed with different size white circles.\n"+
"Together it is a very elegant look. The floor looks like it is made of marble.  The\n"+
"stalls are painted matt-black and there is a long counter with spa-like sinks.  An \n"+
"attendant is handing out towels and offering lotion to the women as they wash their\n"+
"hands.  There is a small powder room area in the rear of the room.\n"+NORM+HIK;  



items = ({
  "walls","Walls lined with elegant silver and white wallpaper",
  "floor","A gorgeous marble floor",
  "stalls","Black bathroom stalls; most of them are in use",
  "counter","A white, granite counter",
  "sink","You see beautiful square, white sinks sitting on top of the counter",
  "powder room","A small counter with two chairs and a very large, lighted mirror.\n"+
  				"It reminds you of a movie star's dressing room",
  "room","A bathroom full of women"



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
	write("You find nothing of interest.\n"); 
	say(TPN+" is looking around.\n");
	return 1;
}

smell()
{
	write("The room is overpowered by floral perfume and aerosol hairspray.\n");
	return 1;
}

listen()
{
	write("It's pretty noisy Sinks running, toilets flushing, doors opening and closing.\n");
	return 1;
}

