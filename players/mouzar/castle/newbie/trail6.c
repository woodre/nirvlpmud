 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "This trail is bring you to a couple of buildings.  The pond turns\n"+
            "into a a river here with a gentle current.  You can see a farm\n"+
            " coming up ahead.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail5","north",
           "/players/mouzar/castle/newbie/trail7","south",
           });
           }
       }
 
 
