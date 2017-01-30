inherit "room/room";

reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc = "Docking Bay";
   long_desc = "You are in the docking bay of the space station known "+
               "as Deep Space Nine, or Tarak'Nor as the Cardassians "+
 	       "would call it. The room is rather metallic, and bland "+
               "and the general atmosphere seems rather depressing. "+
               "There are large windows on both sides of the room, and "+
               "as you look further down the corridor, you see an "+
               "elevator of some sort.\n";
   long_desc = format(long_desc,75);
   items = ({ "window", 
           format("As you look out the window you see that the "+
                  "station is in orbit of the planet Bajor, home of "+
                  "a very spiritual people.  Also you see the "+
                  "impressive sight of a ship coming through the "+
                  "wormhole from the gamma quadrant.\n", 75), }); 
    dest_dir = ({ "/players/gowron/ds9/room/corridor", "north", });
}
