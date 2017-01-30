 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You see a small mansion to the west. To the northwest you can see\n" +
            "a factory of some sort.  To the southeast you can see a star on a \n" +
            "painted on to a building. The village seem to be peacefull.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail15","northwest",
           "/players/mouzar/castle/newbie/trail17","southeast",
           "/players/mouzar/castle/newbie/mansion","west",
           });
           }
       }
 
 
