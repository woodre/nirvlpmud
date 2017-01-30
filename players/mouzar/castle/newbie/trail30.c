 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "There is a building to the west of you.  To the south there is a bridge.\n"+
            "You look down and you see a dog run right past you.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/lock","west",
           "/players/mouzar/castle/newbie/trail99","north",
           "/players/mouzar/castle/newbie/trail29","south",
           });
           }
       }
 
 
