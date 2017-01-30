 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here you see a fork in the road.  There is a trail going east\n" +
            "and a trail going southeast.  To the east you can see some houses.\n" +
            "To the southeast you can see a factory of some sort and a mansion.\n" ;
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail12","northwest",
           "/players/mouzar/castle/newbie/trail15","southeast",
           "/players/mouzar/castle/newbie/trail40","east",
           });
           }
       }
 
 
