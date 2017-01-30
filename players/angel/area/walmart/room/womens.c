/*                                                                              *
 *      File:             /players/angel/area/walmart/room/womens.c             *
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
  short_desc = HIR+"Womens department"+NORM;
  long_desc =
"  "+HIR+"Womens department"+NORM+"\n\
In our womens department we have a fresh new line. Proudly\n\
presenting today's top trends in a collection you can mix and\n\
match in a snap. Indulge your passion for fashion with superior\n\
fabrics in smart silhouettes. We also carry irresistible pajamas\n\
feature an updated, feminine silhouette in dreamy 100% silk.\n";

  items =
  ({
	"departments",
    "This is different areas of the store that sell merchandise\n\
that is unique to that area!",
    "line",
    "Several items put together to form a collection",
    "collection",
    "A line of products produced for one season",
    "fabrics",
    "Material formed by weaving, knitting, pressing,\n\
or felting natural or synthetic fibers",
    "pajamas",
    "Loose fitting nightclothes worn for sleeping or lounging",
    "silk",
    "A fine lustrous fiber composed of insect cocoons",

  });
  dest_dir =
  ({
    "/players/angel/area/walmart/room/softlines",  "softlines",
  });
}
realm(){ return "NT"; }
