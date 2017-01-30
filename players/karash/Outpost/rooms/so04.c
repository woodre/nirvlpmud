
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so04.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the quartermaster room (munitions). 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	
	if( !present("tom hall") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/t_hall"), this_object());
	
	if(arg) return;
   short_desc = GRY+"Outpost Munitions"+NORM;
 long_desc=
"    Just inside the entrance to this building is a waist-high counter\n\
with a laptop sitting upon it.  Behind the counter are many bare\n\
shelves and a scattering of containers and boxes that appear to have\n\
once held weapons, ammunitions, and various other survival tools.\n\
The Munitions exit is to the north.\n";
  set_light(1);
  items=({
    "counter",
"A place where a quartermaster would stand to distribute munitions.\n\
Aside from the laptop, the counter is just as bare as the shelves\n\
behind it",
    "laptop",
"A thin, sleek laptop lies closed on the counter.  A short security\n\
cable attaches it to the counter, which may be the reason it is the\n\
only piece of equipment still found in this place",
	"cable",
"It provides security",
	"security cable","&cable&",
    "shelves",
"Judging from the many empty boxes and containers, these shelves were\n\
once well stocked.  However, it appears this place was emptied in a\n\
hurry and all that is left are empty containers and piles of cellophane\n\
wrapping",
    "containers",
"Various heavy containers lie open and empty across the floor behind\n\
the counter",
    "boxes",
"Piles of empty boxes are scattered around the room",
    "cellophane",
"Piles of used cellophane wrapping are scattered around the room.\n\
Unfortunately, there is no bubble wrap to distract you from your\n\
task at hand",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so02","north",
  });

}

void init()
{
  ::init();
  add_action("auto_doors", "north");
}

auto_doors(str)
{
  tell_object(this_player(),YEL+"\n\The automatic door slides open as you "+NORM+HIR+"EXIT"+NORM+YEL+" the building."+NORM+"\n\n");
  return 0; 
}  

