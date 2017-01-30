 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "This trail leads strait into the village.  To the south is the\n"+
            "Inn of the Brass Tankard where everyone can have a good time.  to\n"+
            "the east is a bridge that crosses the river.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail2","west",
           "/players/mouzar/castle/newbie/trail10","east",
           "/players/mouzar/castle/newbie/inn","south",
           });
           }
       }
 
 
