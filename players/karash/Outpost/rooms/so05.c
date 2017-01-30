
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so05.c
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
	
	if( !present("guard") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/guard"), this_object());
	if( !present("guard 2") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/guard"), this_object());
	
	if(arg) return;
   short_desc = GRY+"Outpost Walkway"+NORM;
 long_desc=
"    You currently stand at the center of the compound on the path that\n\
connects each building.  There are five buildings that surround you.\n\
The four smaller structures, including those to your immediate north\n\
and south have automatic doors to allow easy access.  However, the\n\
larger building next to you to the east is lightly guarded, but it\n\
seems you may still 'enter' if you wish.  The path to exit the compound\n\
leads west.\n";
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
ground from past muddy days.  You currently stand before the largest\n\
of the buildings",
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
	"doors",
"There is a automatic door to your north and south allowing easy access to\n\
the smaller mobile buildings there, and a normal door to your east leading into\n\
the main building, which you may 'enter'",
	"door","&doors&",
	"automatic doors","&doors&",
	"automatic door","&doors&",
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
    "doors",
"You may enter them",
	"door","&doors&",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so06","north",
    "/players/karash/Outpost/rooms/so07","south",
    "/players/karash/Outpost/rooms/so02","west",
    "/players/karash/Outpost/rooms/so08","enter",
  });

}

void init()
{
  ::init();
  add_action("auto_doors", "north");
  add_action("auto_doors", "south");
  add_action("auto_doors2", "enter");  
}

auto_doors(str)
{
  tell_object(this_player(),YEL+"\n\The automatic door slides open as you "+NORM+HIC+"ENTER"+NORM+YEL+" the building."+NORM+"\n\n");
  return 0; 
}  

auto_doors2(str)
{
  if(present("guard"))
  {
    tell_room(this_object(),"The Guard stops you and says, 'I'm sorry, but the Commander is very busy\n\
and I'm not going to let someone else go before me through the slipgate.'\n");
    return 1;
  }
  tell_object(this_player(),YEL+"\n\You open the door and "+NORM+HIC+"ENTER"+NORM+YEL+" the building allowing the door to close behind you."+NORM+"\n\n");
  return 0; 
}  
