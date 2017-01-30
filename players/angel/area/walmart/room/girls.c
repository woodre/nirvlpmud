/*                                                                              *
 *      File:             /players/angel/area/walmart/room/girls.c              *
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
  short_desc = HIR+"Girls department"+NORM;
  long_desc =
"  "+HIR+"Girls department"+NORM+"\n\
Anyone can mix and match from our new collection to create\n\
amazing outfits she'll love. Bundle up beautifully with our\n\
jackets and outerwear. We carry many styles that will match\n\
all of her favorite outfits. There are dozens of accessories\n\
to choose from that can spice up any outfit we sell.\n";

  items =
  ({
    "departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "collection",
    "A line of products produced for this season",
    "outfits",
    "A set of clothing, often with accessories",
    "accessories",
    "Something nonessential but desirable that contributes to an\n\
effect or result",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/softlines", "softlines",	
  });
}
realm(){ return "NT"; }
