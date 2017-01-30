
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so07.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the infirmary within the complex. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	if(arg) return;
   short_desc = GRY+"Outpost Infirmary"+NORM;
 long_desc=
"    The inside of this structure looks like it could be the barracks\n\
of the complex, with some beds to the left and showers to the right.\n\
However, it seems this place also doubled as an infirmary with hints\n\
of medical tools scattered around.  Otherwise, this place is empty.\n\
The infirmary exit is to the north.\n";
  set_light(1);
  items=({
    "beds",
"One would think the beds would be made to look pristine in a complex\n\
such as this, but instead, you see sheets and blankets thrown about as\n\
if the occupants left in a hurry",
    "showers",
"This seems to be the bathroom facilities for this outpost.  Individual\n\
stalls with a shower, toilet and sink are lined against the walls to\n\
the right",
    "tools",
"There are various medical tools laying on the nearby table, but all\n\
medical supplies seem to have been removed",
	"sheets",
"Sheets and blankets are bundled on each bed",
	"blankets","&sheets&",
	"stalls","&showers&",
	"toilets",
"Surprisingly clean toilets sit in each stall, but not providing much\n\
privacy.  They are made of a shiny silver metal that's probably cold\n\
to the touch",
	"toilet","&toilets&",
	"sink",
"Each stall has its own individual metal sink.  Porcelain is probably\n\
a bad idea in a mobile unit like this",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so05","north",
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

