 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here you can see a daycare center to the north. To the west you can\n"+
            "see a open field.  You can see some animals playing in it.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/daycare","north",
           "/players/mouzar/castle/newbie/trail38","west",
           "/players/mouzar/castle/newbie/trail36","east",
        });
           }
       }
 
 

