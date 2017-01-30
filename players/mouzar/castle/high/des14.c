 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  To the east is a mountain range.  Off to the south\n"+
            "you can see an animal of some kind.  You can hear something to the north.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des13", "south",
             "/players/mouzar/castle/high/des15", "north",
             "/players/mouzar/castle/high/des24", "west",
             "/players/mouzar/castle/high/des4", "east",
         });
             
       }
     
         }
