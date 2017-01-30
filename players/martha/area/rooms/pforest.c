#include "ansi.h"
inherit "room/room";

reset(arg) {
     if(!present("mrmint",this_object())) {
       move_object (clone_object("players/martha/area/mobs/mrmint"), this_object());
   }
   
   if (arg) return;
   set_light(1);
   short_desc = RED+"P"+WHT+"e"+RED+"p"+WHT+"p"+RED+"e"+WHT+"r"+RED+"m"+WHT+"i"+RED+"n"+WHT+"t "+RED+"F"+WHT+"o"+RED+"r"+WHT+"e"+RED+"s"+WHT+"t"+NORM;
   items = ({
       "trees","Tall trees shaped like candy canes",
       "forest","A forest of peppermint trees",
       "base","The base of a tree",
       "base of trees","The base where all trees come together",
       "floor","The floor is covered with peppermint shavings",
       "tree","Tall trees shaped like candy canes",
       "instruments","Flutes and piccolos carved from peppermint",
       "peppermint","Hard candy carved into musical instruments"});
       
   long_desc =
"  Enormous "+RED+"red"+NORM+" and "+HIW+"white"+NORM+" "+RED+"p"+WHT+"e"+RED+"p"+WHT+"p"+RED+"e"+WHT+"r"+RED+"m"+WHT+"i"+RED+"n"+WHT+"t"+NORM+" trees line the forest.  The\n\
forest floor is sticky and the air smells of "+RED+"p"+WHT+"e"+RED+"p"+WHT+"p"+RED+"e"+WHT+"r"+RED+"m"+WHT+"i"+RED+"n"+WHT+"t"+NORM+".  The\n\
faint sound of music drifting throughout the forest makes one\n\
want to hum along with it.  Scattered around the base of the\n\
trees are various musical instruments made of "+RED+"p"+WHT+"e"+RED+"p"+WHT+"p"+RED+"e"+WHT+"r"+RED+"m"+WHT+"i"+RED+"n"+WHT+"t"+NORM+".\n\
Maybe they taste as good as they look?\n";
   dest_dir = ({"players/martha/area/rooms/gmtn","east",
                     "players/martha/area/rooms/ptrees","west"});
}
