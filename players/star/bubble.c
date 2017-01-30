/*
 *      File:                 /players/star/bubble.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2006 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               02/11/2006
 *      Notes:
 *      Change History:
 */

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "A Bubble in Space";
  long_desc =
  "   You stand in some kind of odd bubble in space with stars shining\n"+
  "all around you.  Even odder are the small labeled black holes on the\n"+
  "edges of the bubble.\n";

  items =
  ({
    "stars",
    "The stars are shining brightly",
    "holes",
    "The small black holes will take you to different realms",
  });
  dest_dir =
  ({
    "/players/star/hotel/rooms/driveway.c",     "overlook",
    "/room/south/sforst9",     "out",
  });
}
