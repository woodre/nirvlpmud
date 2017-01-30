inherit "/room/room";
#include "/players/autumn/defs.h"


/*TO DO'S: 
* add query ticket to go 'theaters' 
*/

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(BOLD+YEL+"ESC Cinemas: "+NORM+HIB+"Lobby"+NORM);

long_desc=
 
HIK+"The Lobby:\n"+NORM+YEL+
"The ESC Cinema Lobby is vibrant and colorful.  Movie premier posters are displayed neatly\n"+
"near the entrance to the theater.  The concession stand is overly busy with lines out the\n"+
"door.  The game room is crowded with children and there are lines at both restrooms.  The\n"+
"lobby is packed with patrons waiting in line for their movie.  This must be the busiest \n"+
"theater in town!\n"+NORM+HIK;  



items = ({
  
  "lobby","The entrance to a theater",
  "posters","You see five spaces for posters neatly hung on the wall.\n"+
  		"Unfortunately, only the 'fifth' space is displaying a poster right now",
  "fifth",YEL+"                              COMING SOON:\n\n"+NORM+
  		HIB+"                               T"+NORM+HIW+"H"+NORM+RED+ "E"+NORM+HIK+
  		" C"+NORM+HIG+"U"+NORM+HIY+"B"+NORM+HIB+"E\n\n"+NORM+
  		"7 complete strangers of widely varying personality characteristics are\n"+
  		"involuntarily placed in an endless kafkaesque maze containing deadly traps.\n\n"+
  		"Directed by: Vincenzo Natali\n"+
  		"Writers: Andre Bijelic, Vincenzo Natali, Graeme Manson\n"+
  		"Staring: Nicole de Boer, Maurice Dean Wint, David Hewlett, Nicky Guadagni\n"+
  		"         Andrew Miller, Julian Richings, and Wayne Robson"


});

dest_dir = ({
  "/players/autumn/cinemas/rooms/hall3.c","theaters",
  "/players/autumn/cinemas/rooms/concessions.c","concessions",
  "/players/autumn/cinemas/rooms/games.c","games",
  "/players/autumn/cinemas/rooms/womens.c","women",
  "/players/autumn/cinemas/rooms/mens.c","men",
  "/players/autumn/cinemas/rooms/tickets.c","tickets",
  "/players/autumn/cinemas/rooms/service.c","lost and found"


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
  write("Watch it buddy! There will be no pick-pocketing the patrons in this theater!\n"); 
  say(TPN+" is being sneaky.\n");
  return 1;
}

smell()
{
	write("Yummy smells of buttered popcorn and candy are everywhere.\n");
	return 1;
}

listen()
{
	write("You hear popcorn popping! People talking! Laughter everywhere!\n");
	return 1;
}


