
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so08.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the entrance to the main building holding the slipgate. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
    ::reset(arg);
	
	if( !present("commander keen") ) 
    move_object(clone_object("/players/karash/Outpost/mobs/keen"), this_object());
	
	if(arg) return;
   short_desc = GRY+"Entrance to Slipgate"+NORM;
 long_desc=
"    This is the entrance to the main building in this compound.  It is\n\
a small room with a desk on one side and a table with four chairs on\n\
the other side.  Against the back wall, is a small table with a coffee\n\
dispenser.  From here, you see a hint of computer equipment on display\n\
in the room to the north.  There is also a room to the south where a\n\
black-tinted glass door is propped open, but you are unable to see\n\
anything from your viewpoint here.\n";
  set_light(1);
  items=({
    "desk",
"A small wooden desk sits in the corner with a single laptop upon it",
    "laptop",
"A thin sleek laptop lies closed on the desk.  There is a short\n\
security cable that attaches it to the desk",
    "table",
"A small conference table with four chairs sits in the opposite corner\n\
from the desk",
	"conference table","&table&",
    "chairs",
"There are four chairs surrounding the conference table and an office\n\
chair sits behind the desk",
    "coffee table",
"There is a small table against the back wall holding a coffee\n\
dispenser.  Beside the dispenser are some small Styrofoam cups, but\n\
no cream or sugar is noticeable",
    "cups",
"Small Styrofoam coffee cups are stacked upside down next to the\n\
coffee dispenser",
    "dispenser",
"This is a coffee dispenser.  It dispenses coffee",
    "coffee dispenser","&dispenser&",
    "coffee","&dispenser&",
    "entrance",
"Well, it could also be an exit",
    "exit",
"The exit leads back 'out' into the compound",
    "room",
"Yes, this is the entrance to this building",
    "cable",
"It provides security",
	"wall",
"The biege walls are empty besides the desk and tables pushed against them",
	"walls","&wall&",
	"tables",
"A conference table sits to the right and a coffee table sits against the\n\
back wall",
	"computer equipment",
"Various computers can be seen in the room to the north as if it was some\n\
kind of server room",
	"equipment","&computer equipment&",
	"computers","&computer equipment&",
	"server room",
"It appears to be a room... full of computer servers",
	"door",
"There is a black-tinted glass door propped open leading into the room\n\
to the south",
	"glass door","&door&",
	

  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so09","north",
    "/players/karash/Outpost/rooms/so10","south",
    "/players/karash/Outpost/rooms/so05","out",
  });

}

void init()
{
  ::init();
  add_action("get_coffee", "get");
  add_action("auto_doors", "out");
}


auto_doors(str)
{
  tell_object(this_player(),YEL+"\n\You open the door to "+NORM+HIR+"EXIT"+NORM+YEL+" the building allowing the door to close behind you."+NORM+"\n\n");
  return 0; 
}   


get_coffee(str)
{
if(str == "coffee")  
  {
  tell_object(this_player(), "The coffee is a lie.\n");  
  return 1;
  }
}