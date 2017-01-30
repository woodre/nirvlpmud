/*
 *      File:                 /players/star/rooms/pantry.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/03/2005
 *      Notes:
 *      Change History:
 */

#include <ansi.h>

inherit "/room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "The Cold Pantry";
  long_desc =
  "   The pantry is cool and dry, but not so cool as to be uncomfortable.\n"+
  "The shelves are full of food, including boxes of powdered milk,\n"+
  "loaves of bread, and canned goods.  Barrels full of fruits and\n"+
  "vegetables line one wall.\n";

  items =
  ({
    "shelves",
    "The shelves are made of wood, and some have holes in them to allow air\n"+
    "to circulate",
    "food",
    "There is a large variety of food on the shelves",
    "boxes",
     "There are boxes of powdered milk, as well as other things",
    "milk",
    "There is enough powdered milk here to last the winter",
    "loaves",
    "Loaves of bread, in both white and wheat",
    "bread",
    "Loaves of bread, in both white and wheat",
    "goods",
    "Assorted canned goods, from veggies to soups and everything in between",
    "barrels",
    "Wooden barrels filled with fresh fruits and vegetables",
    "fruits",
    "Apples, oranges, etc",
    "vegetables",
    "Carrots, peppers, broccoli, etc",
  });
  dest_dir =
  ({
    "/players/star/rooms/kitchen.c",    "out",
  });
}
