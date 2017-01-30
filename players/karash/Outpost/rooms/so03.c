
inherit "/room/room";

#include <ansi.h>

/******************************************************************************
 * Program: so03.c
 * Path: /players/karash/Outpost/rooms
 * Type: room
 * Created: July 2014 by Karash
 *
 * Purpose: One of the rooms for the introductory area called Slipgate Outpost.
 *			This is the Mess Hall within the complex. 
 * 
 * History:
 *          
 ******************************************************************************/

reset(arg)
{
  ::reset(arg);
	
  if( !present("adrian carmack") ) 
  move_object(clone_object("/players/karash/Outpost/mobs/a_carmack"), this_object());
	
  if(arg) return;
  short_desc = GRY+"Outpost Mess Hall"+NORM;
  long_desc=
"    This structure is obviously a place for feeding a large group of\n\
people.  To the left is the kitchen area with a buffet-type serving\n\
line.  The rest of the area is filled with folding tables and connected\n\
seats similar to those found in most cafeterias.  The cafeteria exit\n\
is to the south.\n";
  set_light(1);
  items=({
    "kitchen",
"One can imagine how noisy this kitchen must get when this cafeteria\n\
is crowded, but for now, the kitchen is empty and quiet",
    "tables",
"The cafeteria tables are lined up for the most efficient use of space\n\
to accommodate as many people as possible at one time.  The tables\n\
still appear to be fairly new, but various scratches and scuff marks\n\
clearly show they have been used",
	"marks",
"The tables appear to be fairly new, but the scratches and marks appear\n\
to be from heavy use of many people sliding into and out of the seats,\n\
typical of a busy cafeteria",
	"scratches","&marks&",
	"scuff marks","&marks&",
	"seats",
"The seats are the round plastic seats you normally see attached to the\n\
folding tables in typical cafeterias",
    "cafeteria",
"From the outside, this building looks fairly small, yet the layout of\n\
this cafeteria looks like it could handle quite a large number of\n\
people at one time.  However, the kitchen is quiet for now",
    "mess hall","&cafeteria&",
	"serving line",
"The kitchen is empty and no food can be found on the buffet",
	"buffet","&serving line&",
	"mountain dew",
"Adrian sees you eyeing his Mountain Dew and takes a sip",
  });

 dest_dir=({
    "/players/karash/Outpost/rooms/so02","south",
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

