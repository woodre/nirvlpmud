/*****************************************************************************
 *      File:                   froom2.c
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
  short_desc="Women's Room";
long_desc=
 "This is the women's room.  The north is lined with four stalls.  It also\n" +
 "holds space for three sinks, two papar towel dispensers, and three hand\n" +
 "blowers.  The Walls are done in a beige tile while the floor is done in\n"+
 "a mixture of black and white tile. Above the entire length of the sinks\n"+
 "is a huge mirror.  Beside the exit there is a hand sanitizing station.\n";
 
items=({
 "sink", "A sink made of steal and covered in marble",
 "mirror", "What do you think a mirror is you idiot",
 "dispenser", "Dispenser that holds paper towels for drying your hands",
 "station", "A small square box filled with sanitizing liquid",
 "liquid", "A clear liquid used to kill germs",
 "blower", "A metal instrument with a steel button used to dry your hands\n"+
 "using hot air",
 });

dest_dir=({
 "/players/highlander/areas/acs/rooms/sprint1.c","out",

           });
        }