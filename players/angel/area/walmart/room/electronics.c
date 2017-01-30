/*                                                                              *
 *      File:             /players/angel/area/walmart/room/electronics.c        *
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
/* case of 'hitachi' corrected, as the id of the monster is 'Hitachi'.
 * Reported to me by Humble 02 mar 2011 - mizan */
 if( !present("Hitachi", this_object()) )
    move_object(clone_object("/players/angel/area/walmart/npc/hitachi.c"), this_object());  
  if( !present("ion", this_object()) )
  {
    for(x=0; x<1; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/ion.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIB+"Electronics"+NORM;
  long_desc =
"   "+HIB+"Electronics Department"+NORM+"\n\
  Get the latest products at Every Day Low Prices in all Electronics\n\
categories, including cell phones, digital cameras, laptops,\n\
monitors, MP3 players and many more. We carry the coolest gadgets\n\
that make the greatest gifts. Find the biggest selection of most\n\
wanted video game titles, consoles and accessories for every hard\n\
core gamer on your list. Buy the new 50 Cent: Bulletproof, where\n\
50 gets caught in a web of corruption, double-crosses and shady\n\
deals that lead him on a war-torn path through New York's underworld.\n\
Shop and save!\n";

  items =
  ({
    "products",
    "Something produced by human or mechanical effort or by a\n\
natural process",
    "product",
    "Something produced by human or mechanical effort or by a\n\
natural process",
    "electronics",
    "We sake many different types of electronic devices and/or\n\
equipment",
    "phones",
    "They are electronic device that receives and emits sound",
    "cameras",
    "An apparatus for taking photographs. We sale many\n\
different models",
    "gadgets",
    "A small specialized mechanical or electronic device",
    "gifts",
    "Something that is bestowed voluntarily and without compensation\n\
from one person to another",
    "video game",
    "An electronic or computerized game played by manipulating images\n\
on a video display or television screen",
    "consoles",
    "Electronic device that play video games",
    "web",
    "An intricate network",
    "deals",
    "transactions between two or more parties",
    "war",
    "To be in a state of hostility or rivalry",
    "path",
    "A trodden track",
    "underworld",
    "The part of society that is engaged in and organized for the\n\
purpose of crime",

  });
  dest_dir =
  ({
    	"/players/angel/area/walmart/room/hardlines", "hardlines",
  });
}
realm(){ return "NT"; }
