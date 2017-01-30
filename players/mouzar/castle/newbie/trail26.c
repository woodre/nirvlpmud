 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "On the side of the trail you can see some flowers blooming.  Off\n"+
            "to the east you can see two buildings and to the west you can see\n"+
            "a fork in the trail.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail25","west",
           "/players/mouzar/castle/newbie/trail27","east",
           });
           }
       }
 
 
