/*
 *      File:                 /players/star/rooms/ballroom.c
 *      Function:
 *      Author(s):            Star@Nirvana
 *      Copyright:            Copyright (c) 2005 Star/Charity Goddard
 *                                    All Rights Reserved
 *      Source:               10/30/2005
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
   short_desc = "The Ballroom of the Overlook Hotel";
   long_desc = 
   "   The Overlook's ballroom is a large and luxurious room.  Looking\n"+
   "around, it is easy to imagine the parties that must go on here during\n"+
   "the tourist season.  It is currently the off-season though, and the \n"+
   "rugs are rolled up against one wall, baring the hardwood beneath.  Two\n"+
   "other walls are lined with tables piled high with chairs.  On the west\n"+
   "wall there is a giant fireplace with huge mirror above it and a clock\n"+
   "on the mantle.  Next to the fireplace a set of batwing doors leads\n"+
   "into the bar and lounge area.  A door on the north wall leads to the\n"+
   "kitchens.\n";

   items =
   ({
      "rugs",
      "The edges of the rolls show just how thick these deep red carpets are",
      "hardwood",
      "This floor is a light shade of brown, and looks perfect for dancing on",
      "tables",
      "The tables shoved against the walls look to be solid oak, and quite\n"+
      "expensive",
      "chairs",
      "The chairs are made of oak to match the tables, and have deep red\n"+
      "cushions",
      "fireplace",
      "The huge fireplace is dead and cold",
      "mirror",
      "As you look into the mirror you see yourself of course, but a word\n"+
      "seems to be floating in front of your reflection.  The word is "+HIR+"REDRUM"+NORM,
      "mantle",
      "The mantle seems to be solid marble",
      "clock",
      "The clock is under a glass dome.  You might be able to wind it with\n"+
      "the key lying next to it on the mantle",
      "key",
      "This little key looks like it can be used to wind the clock",
      "doors",
      "The doors to the west look like the entrance to an old west saloon,\n"+
      "and the ones to the north have small round windows in them",
   });
   dest_dir =
   ({
      HOTEL+"rooms/lobby.c",     "east",
      HOTEL+"rooms/lounge.c",    "west",
      HOTEL+"rooms/kitchen.c",   "north",
   });
}

void init()
{
   ::init();
   add_action("cmd_wind","wind");
}

int cmd_wind(string str)
{
   if(!str)
   {
      notify_fail("Wind what?\n");
      return 0;
   }
   if(str != "clock" && str != "the clock")
   {
      notify_fail("You can only \"wind\" the \"clock\".\n");
      return 0;
   }

   write(
      "You pick up the key and wind the clock.  Two small golden figures, a\n"+
      "boy and a girl, come from little doors in opposite sides of the clock.\n"+
      "They dance for a minute, then the boy raises a mallet and beats the\n"+
      "girl.  Blood spatters all over the inside of the glass, and when it\n"+
      "runs down the dome and disappears the figures are gone.\n");
   say((string)this_player()->query_name()+" winds the clock and stares at it with a look of disgust\n");

   return 1;
}
