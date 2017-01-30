 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You can see the giant woods that surround the small village.  There\n"+
            "is a shop to the north.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail11","west",
           "/players/mouzar/castle/newbie/trail13","southeast",
           "/players/mouzar/castle/newbie/shop","north",
           });
           }
       }
 
 
