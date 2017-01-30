/*                                                                              *
 *      File:             /players/angel/area/walmart/room/gardencenter.c       *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

int x;

reset(arg)
{
  ::reset(arg); 
  if( !present("venus", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/venus.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Garden Center"+NORM;
  long_desc =
"   "+HIB+"Garden Center Department"+NORM+"\n\
  Power Up! Outdoor Tools Built to Last! Make outdoor chores are\n\
a breeze with our wide selection of power washers, generators\n\
and mowers. Perfect for the Barbecue Chef, here's a grill he's\n\
sure to flip over: a terrific new grill he can use year-round.\n\
Entertain with wood to wicker, love seats to lounger's, we've got\n\
the latest looks at the best values. whether its power tools,\n\
grills, patio furniture, or plants we got it all to make the\n\
outdoors look great. Have a great day!\n";

  items =
  ({
    "tool",
    "There are many devices for sale, such as a saw, used to\n\
perform or facilitate manual or mechanical work",
    "tools",
    "There are many devices for sale, such as a saw, used to\n\
perform or facilitate manual or mechanical work",
    "outdoor",
    "You can smell the fresh air outdoors, there is tons of\n\
open air space",
    "chores",
    "A routine or minor duty",
    "power washers",
    "Heavy duty equipment that sprays out water up to 2,000 to 3,000 PSI",
    "generators",
    "A machine that converts mechanical energy into electrical energy",
    "mowers",
    "A mechanical device used to cut down grass",
    "chef",
    "A person who cooks the food",
    "grill",
    "A framework of metal bars where food is cooked",
    "wood",
    "A product made from a tree",
    "wicker",
    "A product made from willow. A flexible plant branch or twig,\n\
as of a willow, used in weaving baskets or furniture",
    "seats",
    "A place in which one may sit",
    "lounger",
    "A long couch, especially one having no back",
    "patio",
    "An outdoor space for dining or recreation that adjoins a\n\
residence and is often paved",
    "furniture",
    "Furnishings that make a room or other area ready for occupancy",
    "plants",
    "A plant having no permanent woody stem, an herb",

  });
  dest_dir =
  ({
   "/players/angel/area/walmart/room/hardlines", "hardlines",	
  });
}
realm(){ return "NT"; }