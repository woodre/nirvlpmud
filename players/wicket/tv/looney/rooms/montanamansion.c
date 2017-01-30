inherit"/room/room";
#include <ansi.h>
 
reset(arg)
{
::reset(arg);
if(arg)return;
  set_light(1);
  short_desc = YEL+"Montana Max"+NORM+"\'"+YEL+"s"+HIK+" Mansion"+NORM;
  long_desc = " A massive building. The roof is made of red clay shingles that glisten\n\
  when the sun hits them. Fancy furniture lines all the rooms, tables of\n\
  solid wood hold lamps and antiques. A self portrait is placed, above the\n\
  fireplace on the mantle of Montana himself. A roaring log fire fills the\n\
  house with warmth. A huge master chair is placed in front of the fireplace,\n\
  a blanket made of money is dropped over the back. To the far corner of the\n\
  house a vault made of solid gold holds Montana\'s money. Evil laughter\n\
  floods the room coming from the vault.\n";
  items = 
  ({
    "fireplace",
    "A massive fireplace made of solid stones",
    "vault",
    "Montana Max\'s personal vault to keep all his money",
    "portrait",
    "A personal portrait of Montana himself, It looks very evil",
    "table",
    "A solid oak table with trinkets and and items on it worth millions of dollars",
    "furniture",
    "Old antique fancy furniture that seems to be very expensive",
    "mantle",
    "A personal place above the fireplace that has a picture of Montana himself",
    "fire",
    "A hot roaring crackling fire that gives warmth to the house",
    "blanket",
    "A blanket made of money that seems to be patched together with fancy gold threads",
  });
   dest_dir=({
  "/players/wicket/tv/looney/rooms/monvault.c","south",
  "/players/wicket/tv/looney/rooms/toonroad1.c","east",
  });
  }