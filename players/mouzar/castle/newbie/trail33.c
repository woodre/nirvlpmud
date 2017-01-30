 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "This is the edge of town.  You see two buildings here.  One is a new\n"+
            "one with a sign above the door that reads 'Fletchery' and another\n"+
            "building to the north that is just a plain home.  Farther east\n"+
            "you can hear wild animals calling to each other.  The cobble stone\n"+
            "trail ends here.  The forest is dark and eerie looking.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail32","west",
           "/players/mouzar/castle/newbie/npath2","east",
           "/players/mouzar/castle/newbie/home4","north",
           "/players/mouzar/castle/newbie/fletcher","south",
           });
           }
       }
 
 
