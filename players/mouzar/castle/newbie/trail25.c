 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here the trail splits to the north.  You can see two more buildings\n"+
            "to the east.  To the west you can see a run down home.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail24","west",
           "/players/mouzar/castle/newbie/trail26","east",
           "/players/mouzar/castle/newbie/trail28","north",
           });
           }
       }
 
 
