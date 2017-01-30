/*                                                                              *
 *      File:             /players/angel/area/school/room/school_hall_04.c      *
 *      Function:         room                                                  *
 *      Author(s):        Angel@Nirvana                                         *
 *      Copyright:        Copyright (c) 2006 Angel (Josh Hatfield)              *
 *                                All Rights Reserved.                          *
 *      Source:           11/15/06                                              *
 *      Notes:                                                                  *
 *                                                                              *
 *                                                                              *
 *      Change History:                                                         *
 */

#include <ansi.h>

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "School Hall";
  long_desc =
"  This is the end of the long hallway. In addition to the class\n\
rooms there is a sign that shows the gym is to the northwest and\n\
the playground to the southwest. This end of the hall seems to be\n\
extra bright from all the glass doors going outside.\n";

  items =
  ({
    "gym",
    "This is a basic gym with hardwood floors, basketball goals,\n\
and bleacher's",
    "playground",
    "Outside you can see many jungle gyms and other toys for the\n\
students to play on",
    "outside",
    "When you exit the doors outside there is a playground and the\n\
sky is clear blue",
    "hallway",
    "This is s long corridor",
    "students",
    "They are average school students",
    "rooms",
    "These are basic class rooms",
    "sign",
    "The sign is made of plastic and hangs from the ceiling",
    "glass doors",
    "Two doors made out of glass",
    "class",
    "a group of students",
    "glass",
    "The glass is very clear",
    "doors",
    "The doors are large and made of glass",
  });
  dest_dir =
  ({
    "/players/angel/area/school/room/grade_04", "north",
    "/players/angel/area/school/room/grade_03", "south",
    "/players/angel/area/school/room/school_hall_03", "east",
    "/players/angel/area/school/room/gym_01", "northwest",
    "/players/angel/area/school/room/playground_01", "southwest",
  });
}