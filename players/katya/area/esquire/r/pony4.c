/*
 *     pony4.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{

  if(!present("autumn"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/autumn.c"),
      this_object());
  }
  
  if(!present("surprise"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/surprise.c"),
    this_object());
  }
  
  if(!present("rainbow"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/rainbow.c"),
    this_object());
  }
/* Here I moved the monster cloning code before the reset so that there */
/* is a check for the monsters each time the room resets. Otherwise, the */
/* monsters may only clone once per reboot. Vital */

  if(!arg)
  { 

    set_light(1);

    short_desc = ""+HIM+"Dream Valley"+NORM+"";

    long_desc="\
  A small sparkling stream flows throw a large field of bright\n\
green grass towards little barn like houses.  The little houses\n\
are full of bright and cheerful colors.  The doors on the houses\n\
swing open like a miniature barn door.  The sun shines beaming \n\
down upon the shining green grass making rainbow colors on the\n\
dew splashed from the stream.\n",
	
    items=({
        "stream",
           "A small stream sparkles with bright clear colors",
        "field",
           "A bright glowing field of green grass",
        "barn",
           "Little houses that look like barns",
        "houses",
           "Little bright colored houses that resemble small barns",
        "doors",
           "The door is short and rounded and full of color ",
        "sun",
           "The sun is quite bright shining down on the field of grass",
        "grass",
           "The green grass flows on for miles and miles",
        "rainbow",
            "Bright and cheerful colors shine across the beautiful stream",
        "dew",
            "The dew spreads beautiful colors across the grass",
    });

    dest_dir=({
        "/players/katya/area/esquire/r/pony3",  "out",
    });
  }
}

