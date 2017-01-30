/*
 *      File:                 /players/star/rooms/apt_bed1.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/29/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>
#include </players/star/defs.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "A Plain Bedroom";
  long_desc =
  "   This bedroom is small and simple.  The walls are painted beige\n"+
  "and the carpet is a light shade of brown.  There are two twin beds in\n"+
  "here, pushed together to make one.  There is a plain yellow bedspread\n"+
  "covering the bed, and next to them there is a night stand with a few\n"+
  "magazines on it.\n";

  items =
  ({
    "walls",
    "The walls are beige and have no pictures on them at all...  really\n"+
    "rather plain",
    "carpet",
    "The plain brown carpet looks like it has seen better days",
    "bed",
    "The beds look rather old and uncomfortable",
    "beds",
    "The beds look rather old and uncomfortable",
    "bedspread",
    "The yellow bedspread looks a little threadbare",
    "night stand",
    "The night stand is rickety, but somehow it is still standing",
    "stand",
    "The night stand is rickety, but somehow it is still standing",
    "magazines",
    "There are a few sporting magazines and a few ladies' ones",
  });
  dest_dir =
  ({
    HOTEL+"rooms/live_room.c",     "west",
  });
}
