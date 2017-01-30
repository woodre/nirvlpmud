 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You wonder what you are doing here.\n"+ 
            "You see nothing but wasteful in ever direction execpt to the east.  There\n"+
            "lies the way out of this dreadful place.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des5", "south",
             "/players/mouzar/castle/high/des16", "west",
             "/players/mouzar/castle/high/des7", "north",
             "/players/mouzar/castle/high/des1", "east",
         });
             
       }
     
         }
