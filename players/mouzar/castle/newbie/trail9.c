 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "The trail has brought you to a farm.  The trail comes to an end.\n"+
            "You can hear ducks quacking from the south.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail8","north",
           "/players/mouzar/castle/newbie/duckyard","south",
           });
           }
       }
 
 
