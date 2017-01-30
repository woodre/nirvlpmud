/*
 *     entrance.c              
 *     Katya@Nirvana
 *     Copyright (c) 2004 Katya
 *     All Rights Reserved.
 *    
 */


#include <ansi.h>

inherit "room/room";

reset(arg) {
  if(!arg)
  { 

  set_light(1);

  short_desc = "The Esquire";

  long_desc="\
  The Esquire has a huge crystal chandelier hanging in the middle of\n\
the ceiling.  As the light flickers through the crystals, rainbows of\n\
flashing strands of light dance upon the room.  Two long hallways lead\n\
to the rooms where the movies are being played.\n";

   items=({
        "esquire",
           "An antique looking movie theatre",
        "crystal",
           "The crystals on the huge chandelier dance rainbows all over the room",
        "chandelier",
           "The chandelier hangs from the highest point of the cathedral ceiling\n\
           reflecting beautiful crystalized rainbows upon the room",
        "ceiling",
           "Rainbows dance along the white cathedral ceiling",
        "light",
           "Light flickers through the chandelier",
        "rainbows",
           "Rainbows prance around the room hitting everything in sight",
        "room",
           "Entrance room of the Esquire movie theatre",
        "hallways",
           "Long hallways go towards the movies that are currently playing",
        "huge crystal chandelier",
           "The chandelier hangs from the highest point of the cathedral ceiling\n\
           reflecting beautiful crystalized rainbows upon the room",
        "crystal chandelier",
           "The chandelier hangs from the highest point of the cathedral ceiling\n\
           reflecting beautiful crystalized rainbows upon the room",	
        "cathedral ceiling",
           "Rainbows dance along the white cathedral ceiling",
        "rainbows of flashing light",
           "Rainbows prance around the room hitting everything in sight",
        "flashing light",
          "Rainbows prance around the room hitting everything in sight",
        "two long hallways",
          "Long hallways go towards the movies that are currently playing",
        "long hallways",
          "Long hallways go towards the movies that are currently playing",
        "movies",
          "The long hallways lead toward the movies",
        "strands",
          "Strands of light dance around the room",
       "strand",
          "Strands of light dance around the room",
       "strands of light",
          "Strands of light dance around the room",
       "hall 1",
          "The first hallway leads east",
       "hall 2",
          "The second hallway leads west",
   });

   dest_dir=({
        "/players/katya/area/esquire/r/e1",  "east",
       "/players/katya/area/esquire/r/concession",  "north",
        "/players/katya/area/esquire/r/w1",  "west",
        "/room/south/sforst6",  "out",
   });}

 }
