
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so01.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the entrance to the complex from Nirvana. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	if(arg) return;
   short_desc = GRY+"Outpost Entrance"+NORM;
 long_desc=
"    As you enter the compound through the opening in the shoddy\n\
wooden barrier, you notice a worn path leading to five rectangular\n\
metal buildings.  There are two structures on both sides of the path\n\
with the largest structure across the compound located in the back\n\
of the fenced area.\n";  
  set_light(1);
  items=({
    "fence",
"The barrier around the perimeter of the compound appears to have been\n\
hastily constructed.  The wooden fence looks shoddy, but stable enough\n\
to stand strong.  There is barbed wire stretched across the top of the\n\
fence, which appears to have been installed just as quickly as the\n\
fence was constructed",
    "barrier","&fence&",
    "path",
"The path that cuts through the compound is nothing more than worn\n\
areas in the heavily treaded grass stretching to each of the buildings.\n\
All along the path, there are heavy boot prints molded into the hard\n\
ground from past muddy days",
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
structure across the compound seems to have much more hardware on the\n\
roof, such as solar panels, satellite dishes, and a towering antenna",
	"building","&buildings&",
    "compound",
"The compound seems to have been placed here recently and there is\n\
evidence of heavy traffic coming through here, yet it seems eerily\n\
quiet at the moment",
    "opening",
"This is the only visible entrance to the compound.  No one seemed to\n\
bother installing a gate",
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
	"wire",
"Barbed wire is stretched across the fence, yet the entrance to the\n\
compound is open",
	"barbed wire","&wire&",
	"entrance",
"Well, from your viewpoint within the compound, this is now the exit",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so02","east",
    "/room/farmroad1","leave",
  });

}

void init()
{
  ::init();
}