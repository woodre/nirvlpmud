 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "This trail is bringing you straight to a village.  You can see Halflings\n"+
            "walking around.  It is a small village but of course it is only\n"+
            "halflings.\n";
          
dest_dir = ({
           "/room/newbie/road10","west",
           "/players/mouzar/castle/newbie/trail2","east",
           });
           }
       }
 
 
