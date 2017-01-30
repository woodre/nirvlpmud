inherit "/room/room.c";
#include "/obj/ansi.h"

void reset(int arg) 
{
   if(arg) return;
   set_light(1);
   
   short_desc = "The Beatdown Lounge";
   long_desc =
   "    " + HIB + ">>>" + NORM + " " + HIY +
   "The Beatdown Lounge"+
   NORM + " " + HIB + "<<<" + NORM + "\n" +

   "    This is a spacious lounge filled with soft beanbag sofas and a totally\n" +
   "  over-the-top level of decor. Pictures and paintings of the OverPowerLord\n" +
   "  hang in almost every spot where there was once a bare patch of wall, and\n" +
   "  it really looks like a who's who of Nirvana is posing there with each\n" +
   "  and every shot there with him. You notice almost immediately a shimmering\n"+
   "  blue light towards the east with an imposing neon sign hanging over it\n"+
   "  saying 'WIZARDS ONLY PLEASE'. The next thing you see of course are the\n"+
   "  vast amounts of food and drink setup in the catering tables spread\n"+
   "  out before you. Okay, so this 'OverPowerLord' guy might be a bit tacky\n"+
   "  but he really knows how to welcome his guests to a good time.\n" +
   "\n" +
   "  The bar is to the north, through the arches of a stuffed white elephant.\n" +
   "  To the south is an observation deck, and to the west is the main plaza.\n";
   
  items = ({

    "floor",
    "The floor appears to be made of some fairly high quality granite tile.",

    "table",
    "There is a vast amount of food here. Maybe you can 'help yourself' to\n"+
    "something while you're hanging out in the lounge.",

    "pictures",
    "It's really crazy... where to begin? There's a picture of OverPowerLord\n"+
    "clinking champagne glasses with Boltar... There's another one where he\n"+
    "has Mizan in a headlock... There's another where he's managed to pin\n"+
    "Pain on his shoulders and is giving a thumbs-up to the camera.\n"+
    "Overall, it's really a bedazzling array of pictures- quite surreal\n"+
    "and entertaining to look at."

/*
    "food",
    "There is a lot of stuff to eat here. 'help yourself' to the goodies!\n"
*/



  });
  
  dest_dir = 
  ({
    "/players/mizan/mines/ROOMS/bar.c","north",
    "/players/mizan/mines/ROOMS/entrance.c", "west",
    "/players/mizan/mines/ROOMS/observation.c", "south",
  });

  set_no_clean(1);
}

init()
{
   ::init();
}

