/*                                       
 *  File:   /players/mosobp/areas/TOWER/rooms/t25.c    
 *  Function:  room                      
 *  Author(s):  Mosobp@Nirvana           
 *  Copyright: copyright (c) 2008 Mosobp 
 *             all rights reserved            
 *                                       
 *                                       
 *  Source:  7/17/08                     
 *  Notes:                               
 *                                       
 *                                       
 *  Change History:                      
 */
#include "/sys/lib.h"

#include "/obj/ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if( !present("korrin", this_object()) )
  move_object(clone_object("/players/mosobp/areas/TOWER/NPC/korrin.c"), this_object());
  if(arg) return;
  set_light(1);
  short_desc = GRN+"Kame's House"+NORM;
  long_desc = 
  "  "+HIG+"The inside of Kame's house is furnished with a table\n"+
  "in the center of the room.  Chairs are pushed into the table.\n"+
  "In the corner of the room some sacks are sitting behind a counter."+NORM+"\n";
 
  items=
  ({
    "chairs",
    "There are chairs sitting around the tablet",
    "table",
    "There is a table in the center of the room",
    "sacks",
    "There are some sacks laying in the corner of the room",
    "counter",
    "There is a sign on the green marble counter",
    "sign",
    "Maybe you could read it",   
   });
  
  dest_dir =
  ({
    "/players/mosobp/areas/TOWER/rooms/t10.c",  "out",
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
  write(" "+HIG+"Currently Out of Sensu Beans they are coming soon."+NORM+"\n");
  return 1;
}
