 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Off to the east you can make out two buildings.  One looks kinda\n"+
            "new, you can make out a sign hanging over the door.  To the west\n"+
            "you have a home with a little garden in the front yard.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail31","west",
           "/players/mouzar/castle/newbie/trail33","east",
           });
           }
       }
 
 
