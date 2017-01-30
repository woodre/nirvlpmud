/*                                       
 *  File:   /players/mosobp/areas/BATTLE/rooms/b6.c    
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
  short_desc = GRN+"An open field"+NORM;
  long_desc =
  "  An open area of land with plush green grass\n"+
  "all around. Far off to the east a cliff rises into\n"+
  "the sky. The sky seems to darken as it nears the cliff.\n"+
  "A gopher pokes his head out of his hole.\n";

  items=
  ({
    "grass",
    "Plush green grass with flowers occasionally growing in it",
    "cliff",
    "The cliff is off to the east",
    "sky",
    "The sky above is clear and normal, as it reaches the cliff it darkens",
    "gopher",
    "A furry little gopher sticking his head up",
  });

  dest_dir =
  ({
    "players/mosobp/areas/BATTLE/rooms/b3.c",   "north",
    "players/mosobp/areas/BATTLE/rooms/b7.c",   "east",
    "players/mosobp/areas/BATTLE/rooms/b2.c",   "northwest",
    "players/mosobp/areas/BATTLE/rooms/b11.c",  "southeast",
    "players/mosobp/areas/BATTLE/rooms/b10.c",  "south",
    "players/mosobp/areas/BATTLE/rooms/b9.c",   "southwest",
    "players/mosobp/areas/BATTLE/rooms/b5.c",   "west",
  });
}