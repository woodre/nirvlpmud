 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "To the northwest you can see a small farmhouse. To your south\n"+
            "you can see a home.  Off to the east there is a nice building\n"+
            "with alot of Halflings going in and out of it.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail19","northwest",
           "/players/mouzar/castle/newbie/trail21","southeast",
           "/players/mouzar/castle/newbie/home2","south",
           });
           }
       }
 
 
