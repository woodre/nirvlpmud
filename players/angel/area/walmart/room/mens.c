/*                                                                              *
 *      File:             /players/angel/area/walmart/room/mens.c               *
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
  if( !present("mannequin", this_object()) )
  {
    for(x=0; x<2; x++)
    {
    move_object(clone_object("/players/angel/area/walmart/npc/manakin.c"), this_object());
    }
}
if(arg) return;
  set_light(1);
  short_desc = HIR+"Mens department"+NORM;
  long_desc =
"  "+HIR+"Mens department"+NORM+"\n\
We have everything a man needs to be a sharped dress man.\n\
Everything we carry is always in style, just like our cashmere\n\
buttery-soft and resilient crewneck's or polo's in a variety of\n\
rich colors.\n";

  items =
  ({
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "man",
    "An adult male human",
    "cashmere",
    " A soft fabric made of wool or of similar fibers",
    "crewnecks",
    "A garment, especially a sweater with a round close-fitting neckline",
    "polos",
    "The classic Polo shirt is a pull over short sleeve",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/softlines", "softlines",	
  });
}
realm(){ return "NT"; }