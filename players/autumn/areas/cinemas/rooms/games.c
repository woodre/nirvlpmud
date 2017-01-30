inherit "/room/room";
#include "/players/autumn/defs.h"


/*TO DO'S: 
* add game objects/extend to realms: donkey kong, pac-man, centipede, MK
* add playGames()
*/

reset(arg) {

    if(arg) return;
    set_light(1);

short_desc=(BOLD+YEL+"ESC Cinemas: "+NORM+MAG+"Game Room"+NORM);

long_desc=
 
HIK+"The Game Room:\n"+NORM+YEL+
"The game room is a rather small room, full of classic video game machines.  The walls are \n"+
"lined with wallpaper of space, planets, and spaceships.  The floor is tiled with different\n"+
"color tiles.  In the center of the room there is a bill breaker.\n"+NORM+HIK;  



items = ({
  "machines","You see a room full of classic video games",
  "walls","The walls look like the solar system has come to life",
  "floor","Large, square, colorful tiles",
  "breaker","A machine that takes $1's, $5's, $10's, and $20's and give quarters"



});

dest_dir = ({
  "/players/autumn/cinemas/rooms/hall3.c","lobby",
  "/players/autumn/cinemas/rooms/concessions.c","concessions",



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
	write("Yummy smells of buttered popcorn and candy are everywhere.\n");
	return 1;
}

listen()
{
	write("You hear a lot of awesome sounds coming from the video games.\n");
	return 1;
}

