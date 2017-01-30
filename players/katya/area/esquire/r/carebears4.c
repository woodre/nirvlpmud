/*
 *     carebears4.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  if(!present("funshine"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/funshine.c"),
      this_object());
  }

  if(!present("bedtime"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/bedtime.c"),
    this_object());
  }

  if(!present("love"))
  {
    move_object(clone_object("/players/katya/area/esquire/m/love.c"),
    this_object());
  }
/* Moved the code to clone the monsters before the check for an arg so */
/* that the monsters will check and clone each reset. Vital */

  if(!arg)
  { 
    set_light(1);

    short_desc = HIR+"Care-A-Lot"+NORM;

    long_desc="\
  Bright rainbows run over head across a field of fluffy clouds.\n\
A small stream flows down from a steep hill made of sparkling\n\
white clouds and creates a little swirling pond.  Bright and \n\
cheerful gardens are on either side of every front door.  Almost\n\
everything here is made out of fluffy, white clouds, except the \n\
care-a-lot meter, which is a huge heart made of a large red,\n\
fluffy clouds placed in the center of Care-A-Lot.\n",

    items=({
      "clouds",
        "Large fluffy white clouds cover the area as far as the eye can see",
      "fluffy clouds",
        "Large fluffy white clouds cover the area as far as the eye can see",
      "rainbows",
        "Bright rainbows shine every color imaginable",
      "field",
        "A large field full of huge, white clouds",
      "stream",
        "A small rainbowed filled stream flows slowly from the top of a cloudy hill ",
      "hill",
        "A steep hill with a rainbowed stream trickling down its soft white surface",
      "pond",
        "A pond of swirling colors gathers at the base of a cloud covered hill",
      "gardens",
        "Bright and cheerful gardens are spread across the lands surrounding every bear's home",
      "care-a-lot meter",
        "A large red heart made out of clouds that keeps track of all the caring in the world",
      "meter",
        "A large cloud shaped like a red heart that keeps track of all the caring in the world",
      "care-a-lot",
        "Care-a-lot is the home of the carebears, who make sure that caring stays alive",
    });

    dest_dir=({
        "/players/katya/area/esquire/r/carebears3",  "out",
    });
  }
}

