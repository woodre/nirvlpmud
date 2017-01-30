 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "This trail is bring you strait to a village.  You can see Halflings\n"+
            "walking around.  It is a small village but of course it is only\n"+
            "halflings.  You can see another trail running to the south.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail3","east",
           "/players/mouzar/castle/newbie/trail4","south",
           });
           }
       }
 
 
