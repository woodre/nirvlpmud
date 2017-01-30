 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "As you walk you can see a dog run past you.  It is so quick you\n"+
            "don't even have a chance to swing at it.  To the east you see a\n"+
            "farm coming up. West ward you see a home.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail21","west",
           "/players/mouzar/castle/newbie/trail23","east",
           });
           }
       }
 
 
