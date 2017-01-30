/*                                       
 *  File:   /players/mosobp/areas/BATTLE/rooms/b10.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  6/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */

#include "/sys/lib.h"

#include "ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = HIG+"An open field"+NORM;
  long_desc =
  "  An open area of land with plush green grass\n"+
  "all around. Far off to the east a cliff rises into\n"+
  "the sky. The sky seems to darken as it nears the cliff.\n"+
  "There is a base of a tower here in the middle of the field.\n"+
  "A line of ants walks along the ground.\n";

  items=
  ({
    "grass",
    "Plush green grass with flowers occasionally growing in it",
    "cliff",
    "The cliff is off to the east",
    "sky",
    "The sky above is clear and normal, as it reaches the cliff it darkens",
    "ants",
    "A line ants walking toward an ant hill",
	"tower",
	"The base of the tower to Kame's Place. There is a sign on the tower",
	"sign",
	"Maybe you could read the sign"
  });

  dest_dir =
  ({
    "players/mosobp/areas/BATTLE/rooms/b5.c",   "northwest",
    "players/mosobp/areas/BATTLE/rooms/b6.c",   "north",
    "players/mosobp/areas/BATTLE/rooms/b7.c",   "northeast",
    "players/mosobp/areas/BATTLE/rooms/b11.c",  "east",
    "players/mosobp/areas/BATTLE/rooms/b16.c",  "southeast",
    "players/mosobp/areas/BATTLE/rooms/b15.c",  "south",
    "players/mosobp/areas/BATTLE/rooms/b14.c",  "southwest",
    "players/mosobp/areas/BATTLE/rooms/b9.c",   "west",
	"players/mosobp/areas/TOWER/rooms/t1.c",    "jump",
  });
  return 1;
}
init()
{
  ::init();
  add_action("cmd_read", "read");
}

cmd_read(str)
{
  if(!str)
  {
    notify_fail("What would you like to read?\n");
    return 0;
  }
  if(str != "sign")
  {
    notify_fail("You can only read the sign.\n");
    return 0;
  }
  write(" "+RED+"Beware climbing the tower can be a tax on your stamina"+NORM+"\n");

  return 1;
}