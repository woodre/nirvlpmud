inherit"/room/room";
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  There is a loud roar to the west.  Are you scared now?\n";
 
  dest_dir = ({
               "/players/mouzar/castle/high/des50", "south",
               "/players/mouzar/castle/high/des51", "north",
               "/players/mouzar/castle/high/des61", "west",
               "/players/mouzar/castle/high/des41", "east",
         });
             
       }
     }
