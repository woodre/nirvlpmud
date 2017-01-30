 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "The trail has brought you to a farm.  To the east you can see some\n"+
            "cows grazing buy the river.  Farther to the south you can see a\n"+
            "farm house.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail6","north",
           "/players/mouzar/castle/newbie/trail8","south",
           "/players/mouzar/castle/newbie/pasture1","east",
           });
           }
       }
 
 
