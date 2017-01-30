 
 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A small dirt trail";
long_desc = "The trail has brought you to a farm.  To the east you can see some\n"+
            "cows grazing by the river.  To the west there is a farm house.\n";
          
dest_dir = ({
           "/players/mouzar/castle/newbie/trail7","north",
           "/players/mouzar/castle/newbie/trail9","south",
           "/players/mouzar/castle/newbie/farmc1","west",
           "/players/mouzar/castle/newbie/pasture2","east",
           });
           }
       }
 
