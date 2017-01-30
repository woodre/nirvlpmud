inherit"/room/room";
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?\n";
 
  dest_dir = ({
               "/players/mouzar/castle/high/des55", "south",
               "/players/mouzar/castle/high/des57", "north",
               "/players/mouzar/castle/high/des56", "west",
               "/players/mouzar/castle/high/des46", "east",
         });
             
       }
     }
