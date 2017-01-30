 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "To the east you can see a nice little home.  To the west you can\n"+
            "see a nice sized home.  Off to your south is a home with a well\n"+
            "kept yard.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail36","west",
           "/players/mouzar/castle/newbie/trail34","east",
           "/players/mouzar/castle/newbie/home6","south",
           });
           }
       }
 
 
