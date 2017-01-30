 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You can see a nice size farm to the east.  To the north you can\n"+
            "see a small bridge.  The trail turns southeast to some little\n"+
            "houses. \n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/farma1","east",
           "/players/mouzar/castle/newbie/trail20","southeast",
           "/players/mouzar/castle/newbie/trail18","north",
           });
           }
       }
 
 
