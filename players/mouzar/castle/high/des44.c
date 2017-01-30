inherit"/room/room";
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  You can see some trees coming up to the north!\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des43", "south",
             "/players/mouzar/castle/high/des45", "north",
             "/players/mouzar/castle/high/des54", "west",
             "/players/mouzar/castle/high/des34", "east",
         });
             
       }
     
}
 
 
