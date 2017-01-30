/*
 *      File:                   filename.c
 *      Function:               
 *      Author(s):              YourName@Nirvana
 *      Copyright:              Copyright (c) 2004 YourName
 *                                      All Rights Reserved.
 *      Source:                 05/24/2004
 *      Notes:                  
 *      Change History:
 */

#include "../defs.h"

inherit "/room/room.c";

void reset(status arg)
{
  ::reset(arg);
  if (arg) 
    return;
  
  short_desc = YEL+"A Subterranean Cavern"+NORM;
  long_desc = "\
Slimy, phosphorescent walls surround you, supplying the weak light.\n\
From a pool of water in almost the exact center of this enormous\n\
grotto, the floor slopes up gradually levelling out into a wide, flat\n\
ring - reminiscent of a giant funnel perhaps.\n";
  add_property("NT");
  items = ({
    "walls", "They are covered in some kind of glowing slimy substance",
    "substance", "It gives off a faint musty odor and a weak glow",
    "slime", "It gives off a faint musty odor and a weak glow",
    "floor", "\
Similar to a funnel, it's flat ground from the walls to where it starts\n\
to slope downwards, eventually ending in a dark pool of water",
    "water", "A dark pool of water sits in the center of the cavern.\
You could perhaps 'dive' into it",
    "pool", "@water",
    "funnel", "@floor",
    "center", "@pool",
    "grotto", "You're in a giant cavern"
  });
  dest_dir = ({
    RPATH+"moat1", "dive"
  });
}











/* 
 * Function name:
 * Description:
 * Arguments:
 * Returns:
 */
