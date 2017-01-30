 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here you can see a run down home to the south.  It looks like it\n"+
            "could be abandon but you see a Halfling in it.  To the west you can\n"+
            "see a farm and to your east you can see a home with lots of wood\n"+ 
"stacked up around it.  The road also splits up farther up east.\n";
            
dest_dir = ({
           "/players/mouzar/castle/newbie/trail23","west",
           "/players/mouzar/castle/newbie/trail25","east",
           "/players/mouzar/castle/newbie/home3","south",
           });
           }
       }
 
 
