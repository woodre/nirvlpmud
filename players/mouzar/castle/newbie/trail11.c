 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small cobble stone trail";
long_desc = "Here the trail is made out of cobblestone.  Your ears are fill with\n"+
            "the activities of the village.  To the south of you is a mill with\n"+
            "a bakery in it.  You are taken away by the sent of the fresh bread\n"+
            "being made.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail10","west",
           "/players/mouzar/castle/newbie/trail12","east",
           "/players/mouzar/castle/newbie/mill","south",
           });
           }
       }
 
 
