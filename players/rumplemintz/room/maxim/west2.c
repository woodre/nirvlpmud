/* ========================================================================== */
/*                                                                            */
/*   west2.c                                                                  */
/*   (c) 2005 Rumplemintz                                                     */
/*                                                                            */
/*   Den in King Maxim's castle                                               */
/*                                                                            */
/* ========================================================================== */

#pragma strict_types

inherit "/room/room.c";

void reset(status arg){
  if(arg) return;
  set_light(1);
  short_desc = "The den of King Maxim's castle";
  long_desc =
"     You are in the den of the castle. There is a fireplace burning\n"+
"brightly on one wall. The warmth of which must be heating the entire\n"+
"castle. There is a black bearskin rug lying on the floor. On one wall\n"+
"is a library of bookshelves, containing an impressive book collection.\n";
  items = ({
    "den", "It's a den, or sitting room",
    "fireplace", "A hearty fire is burning, warming your body",
    "rug", "The hide of a black bear",
    "bearskin rug", "The hide of a black bear",
    "floor", "It is covered with a bearskin rug",
    "booskshelves", "They contain a good collection of books",
    "books", "An impressive collection of literary works"
  });
  dest_dir = ({
    "/players/rumplemintz/room/maxim/foyer2", "east"
  });
}
