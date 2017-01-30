
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so06.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the barracks within the complex. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	
	if( !present("sandy petersen") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/s_petersen"), this_object());
	if( !present("american mcgee") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/a_mcgee"), this_object());
	
	if(arg) return;
   short_desc = GRY+"Outpost Barracks"+NORM;
 long_desc=
"    This structure serves as the sleeping quarters for whomever occupied\n\
this area.  There are bunkbeds lined up from wall to wall on the left\n\
side of this building.  The right side of this large room is tiled from\n\
the floor to the ceiling and appears to have been showers at one time.\n\
However, the showers have been gutted and the walls have been removed\n\
to make room for additional bunks.  The barracks exit is to the south.\n";
  set_light(1);
  items=({
    "beds",
"One would think the beds would be made to look pristine in a complex\n\
such as this, but instead, you see sheets and blankets thrown about as\n\
if the occupants left in a hurry",
    "bunkbeds","&beds&",
    "bunks","&beds&",
	"sheets",
"Sheets and blankets are bundled on each bed",
	"blankets","&sheets&",
	"tiles",
"The tiles still have that new shine to them, but the floor is scratched\n\
from the beds that were placed there",
	"showers",
"There are no showers.  They have been removed to make room for beds",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so05","south",
  });

}

void init()
{
  ::init();
  add_action("auto_doors", "south");
}

auto_doors(str)
{
  tell_object(this_player(),YEL+"\n\The automatic door slides open as you "+NORM+HIR+"EXIT"+NORM+YEL+" the building."+NORM+"\n\n");
  return 0; 
}  

