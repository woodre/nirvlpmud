 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here you are at a dead end.  There is a vintage to the east and\n"+
            "a woodcarver's shop to the south.  You can see a flower patch off to the\n"+
            "west.  The forest looms just past the two home.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail26","west",
           "/players/mouzar/castle/newbie/vintners","east",
           "/players/mouzar/castle/newbie/woodshop","south",
           });
           }
       }
 
 
