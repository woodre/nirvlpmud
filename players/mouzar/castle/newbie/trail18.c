 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small bridge";
long_desc = "You are on a small bridge.  There is a small stream which flows under\n"+
            "you.  To the north you can see a home with a star painted on it.\n "+
            "You can see a farm house coming up to your south.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail17","north",
           "/players/mouzar/castle/newbie/trail19","south",
           });
           }
       }
 
 
