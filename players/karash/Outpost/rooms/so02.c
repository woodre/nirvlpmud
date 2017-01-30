
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so02.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the pathway through the complex. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	if(arg) return;
   short_desc = GRY+"Outpost Walkway"+NORM;
 long_desc=
"    You stand on the path that cuts through the center of the compound\n\
between the two structures closest to the compound entrance.  These\n\
buildings are to the north and south and appear to have an automatic door\n\
allowing easy access.  More buildings lie to the east.\n";
  set_light(1);
  items=({
    "fence",
"The barrier around the perimeter of the compound appears to have been\n\
hastily constructed.  The wooden fence looks shoddy, but stable enough\n\
to stand strong.  There is barbed wire stretched across the top of the\n\
fence, which appears to have been installed just as quickly as the fence\n\
was constructed",
    "barrier","&fence&",
    "path",
"The path that cuts through the compound is nothing more than worn\n\
areas in the heavily treaded grass stretching to each of the buildings.\n\
All along the path, there are heavy boot prints molded into the hard\n\
ground from past muddy days.  Each branch of the path leads to an\n\
automatic door into each building",
	"ground",
"The grounds of the entire compound look like there was a lot of recent\n\
activity here with heavily treaded areas around the outskirts of the\n\
compound where some form of training may have occurred, and of course, the\n\
heavily worn path between the buildings",
	"prints",
"The many, many boot prints molded into the hard ground serve as evidence\n\
that the past occupants of this compound were extremely active, even\n\
through heavy rains",
    "buildings",
"The buildings appear to be metal rectangular mobile units.  There are\n\
two units on each side of the path and a much larger unit on the\n\
opposite side of the entrance.  It appears these structures have been\n\
suddenly dropped here and quickly anchored to the ground.  The larger\n\
structure at the far end of the compound seems to have much more\n\
hardware on the roof, such as solar panels, satellite dishes, and a\n\
towering antenna",
	"building","&buildings&",
	"door",
"There is a automatic door to your north and south allowing easy access\n\
to the smaller mobile buildings there",
	"automatic door","&door&",
	"doors","&door&",
    "compound",
"The compound seems to have been placed here recently and there is\n\
evidence of heavy traffic coming through here, yet it seems eerily\n\
quiet at the moment",
    "structures","&buildings&",
	"solar panels",
"These mobile buildings seem to be self-sufficient, gaining their power\n\
from the large solar panels on the main building",
	"panels","&solar panels&",
	"satellite dishes",
"There are several satellite dishes about 3 foot in diameter on the roof of\n\
the main building pointing in various directions",
	"dishes","&satellite dishes&",
    "antenna",
"There is a towering antenna that rises far above the walls of the\n\
compound, signifying that to remain hidden is not the priority of\n\
this compound",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so03","north",
    "/players/karash/Outpost/rooms/so05","east",
    "/players/karash/Outpost/rooms/so04","south",
    "/players/karash/Outpost/rooms/so01","west",
  });

}

void init()
{
  ::init();
  add_action("auto_doors", "north");
  add_action("auto_doors", "south");
}

auto_doors(str)
{
  tell_object(this_player(),YEL+"\n\The automatic door slides open as you "+HIC+"ENTER"+NORM+YEL+" the building."+NORM+"\n\n");
  return 0; 
}  

