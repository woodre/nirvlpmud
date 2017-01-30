/*                                       
 *  File:   /players/mosobp/areas/BATTLE/rooms/b22.c    
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

#include "/obj/ansi.h"

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = GRN+"An Open Field"+NORM;
  long_desc =
  "  An open area of land with plush green grass\n"+
  "all around. Far off to the east a cliff rises into\n"+
  "the sky. The sky seems to darken as it nears the cliff.\n";

  items=
  ({
    "grass",
    "Plush green grass with flowers occasionally growing in it",
    "cliff",
    "The cliff is off to the east",
    "sky",
    "The sky above is clear and normal, as it reaches the cliff it darkens",
  });

  dest_dir =
  ({
    "players/mosobp/areas/BATTLE/rooms/b21.c",  "west",
    "players/mosobp/areas/BATTLE/rooms/b17.c",  "northwest",
    "players/mosobp/areas/BATTLE/rooms/b18.c",  "north",
    "players/mosobp/areas/BATTLE/rooms/b19.c",  "northeast",
    "players/mosobp/areas/BATTLE/rooms/b23.c",  "east",
  });
}