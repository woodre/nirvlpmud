 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You can see the giant woods looming over the homes to the north.\n"+
            "Off to the west you can see a split in the road.  To the east you\n"+
            "can see a home.  North you can see a cute little home.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail35","west",
           "/players/mouzar/castle/newbie/trail31","east",
           "/players/mouzar/castle/newbie/home5","north",
           });
           }
       }
 
 
