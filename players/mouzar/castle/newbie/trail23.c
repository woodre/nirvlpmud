 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "You follow the trail some more and find a farm to the south and\n"+
            "off to the east you can a small home that looks like someone\n"+
            "hasn't live in it for some time.  To the west you can see\n"+
            "open trail.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail22","west",
           "/players/mouzar/castle/newbie/trail24","east",
           "/players/mouzar/castle/newbie/farmb1","south",
           });
           }
       }
 
 
