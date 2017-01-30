/*
 *      File:                 /players/star/rooms/bedrm1.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               11/23/2005
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
  short_desc = "A Child's Bedroom";
  long_desc =
  "   This room is wallpapered with cowboys and cacti and the carpet is\n"+
  "bright blue.  There is a set of bunk beds along one wall but only the\n"+
  "top bunk looks slept in.  The covers are thrown back as if the child\n"+
  "who slept there was in a hurry to meet the new day.  The bottom bunk\n"+
  "is neatly made, and an open book is laying on it.  There is a\n"+
  "bookshelf in one corner with a few more books on it.  Sitting on top\n"+
  "of the bookshelf is an unopened box containing a model car.\n";

  items =
  ({
    "wallpaper",
    "The wallpaper is blue, with little cartoon cowboys and cacti all over\n"+
    "it",
    "cowboys",
    "The cowboys are quite cute, all dressed in brown and holding lassos",
    "cacti",
    "The cacti are green and pointy",
    "beds",
    "The beds are covered in a blue bedspread to match the rest of the room",
    "bunk beds",
    "The beds are covered in a blue bedspread to match the rest of the room",
    "bunk",
    "Bunk?  Which bunk?  The top looks slept in, the bottom looks nice and\n"+
    "neat",
    "covers",
    "The covers are blue",
    "book",
    "The book lying open on the bottom bunk has a picture of two small\n"+
    "children and a dog.  The text says, 'See Dick.  See Jane.  See Dick\n"+
    "and Jane play with Spot'",
    "bookshelf",
    "The bookshelf is small and made of wood",
    "books",
    "The books on the shelf seem to be of varying skill levels",
    "box",
    "The box is small and shows a picture of the finished model car inside",
    "car",
    "The car is bright purple, and has a little monster sticking out of the\n"+
    "sunroof",
  });
  dest_dir =
  ({
    HOTEL+"rooms/live_room.c",     "north",
  });
}
