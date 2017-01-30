/*
 *      File:                 /players/star/rooms/freezer.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/03/2005
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
  short_desc = "A Walk-in Freezer";
  long_desc =
  "   BRRRR!  It is cold in here!  The shelves surrounding you are full\n"+
  "of frozen food.  It is more than enough to keep a caretaker and his\n"+
  "family through the winter months.  One of the shelves even contains a\n"+
  "turkey for Thanksgiving and a ham for Christmas.\n";

  items =
  ({
    "shelves",
    "The shelves in here are made of metal and are covered in ice and\n"+
    "frost, as well as food",
    "food",
    "There is a very wide assortment of food on the shelves",
    "turkey",
    "This bird was well fed.  And he looks like he would feed an army",
    "ham",
    "This was a very large pig",
  });
  dest_dir =
  ({
    HOTEL+"rooms/kitchen.c",     "out",
  });
}
