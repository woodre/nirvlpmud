inherit"/room/room";
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  You hear moaning coming from the south\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des37", "south",
             "/players/mouzar/castle/high/des39", "north",
             "/players/mouzar/castle/high/des48", "west",
             "/players/mouzar/castle/high/des28", "east",
         });
             
       }
     
}
 
 
