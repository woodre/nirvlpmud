/*****************************************************************************
 *      File:                   mroom2.c
 *      Function:               room for acs area
 *      Author(s):              Highlander@Nirvana
 *      Copyright:              Copyright (c) 2011 Highlander 
 *                              All Rights Reserved.
 *      Source:                 2/24/2011
 *      Notes:                 
 *      Change History:         
 ****************************************************************************/
inherit "room/room";
reset(arg){
  set_light(1);
  short_desc="Men's Room";
long_desc=
 "This is the men's room.  The north is lined with two urinals and two stalls.\n" +
 "It also holds space for three sinks, two paper towel dispensers, and three\n" +
 "hand blowers. The Walls are done in a beige tile while the floor is done in\n"+
 "a mixture of black and white tile.  Above the entire length of the sinks is\n"+
 "a huge mirror.  Beside the exit there is a hand sanitizing station.\n";  

items=({
 "sink", "A sink made of steal and covered in marble",
 "urinal", "A porcelain toilet",
 "mirror", "What do you think a mirror is you idiot",
 "dispenser", "Dispenser that holds paper towels for drying your hands",
 "station", "A small square box filled with sanitizing liquid",
 "liquid", "A clear liquid used to kill germs",
 "blower", "A metal instrument with a steel button used to dry your hands using hot air",
 
 }); 


dest_dir=({
 "/players/highlander/areas/acs/rooms/sprint1.c","out",

           });
        }
