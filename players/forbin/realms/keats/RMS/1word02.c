/*
 *  Created:      Forbin@Nirvana
 *  Copyright:    Copyright (c) 2004 Forbin
 *                  All Rights Reserved.
 *  Function:     City of Keats
 *  Create Date:  2004.06.18
 *  Last Edit:    2004.06.18 -Forbin
 *  Notable Changes:
 */

#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) 
{
  if(arg) return;
  short_desc = KEATS;
  Location = "Avenue of the Word";
  long_desc = 
    "\n                "+HIW+"The Avenue of the Word"+C+"  (["+NORM+"north"+C+"])"+NORM+"\n"+
    "                "+HIW+"The Walk of the Poets"+C+"   (["+NORM+"east,west"+C+"])"+NORM+"\n"+    
    "Just inside the city's gates, The Avenue of the Word begins from a\n"+
    "large plaza and heads north into the city.  Its wide lane is split\n"+
    "down the middle by a sizable median of grass and trees as it snakes\n"+
    "its way up a steep slope further into Keats.  To the left and right\n"+
    "of the plaza are smaller gates which lead to The Walk of the Poets,\n"+
    "a small road that encircles the entire city and allows the garrison\n"+
    "of the Poet Guard to defend the citadel in times of conflict.  Many\n"+
    "buildings stand along the edge of the plaza, and people bustle by.\n";
  add_item(({"gate","gates"}),
    "A large set of gates stand to the south.  Stretching many men high and wide,\n"+
    "they are massive in scale.  Two wood and steel doors hang within its bulk");
  add_item(({"door","doors"}),
    "Each pair of doors are made of a dark, weathered wood.  Several iron\n"+
    "bands run horizontally across each door.  Currently, they are open");
  add_item(({"avenue","avenue of the word","avenue of word","lane"}),
    "The Avenue of the Word begins here, running north further into Keats");
  add_item(({"walk","walk of poets","walk of the poets","road"}),
    "The Walk of the Poets runs both east and west here, providing a somewhat\n"+
    "circular means of traversing the city");
  add_item(({"median","grass","tree","trees"}),
    "The median that splits The Avenue of the Word is beautifully landscaped with\n"+
    "lush, green grass and several types of small, deciduous tree species");
  add_item(({"plaza","building","buildings"}),
    "Buldings, mostly resturants and shops, surround the plaza in a coccoon of\n"+
    "capitalistic pleasure, though none of the places look to interest you");
  add_item("people",
    "People bustle around Keats, darting in and out of the buildings along the,\n"+
    "plaza");
  add_exit(RMS+"1word01.c", "north");
  add_exit(RMS+"1bridge.c", "leave");
  set_light(1);
}
