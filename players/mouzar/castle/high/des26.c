inherit"/room/room";
int i;
 
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "As you enter the room .\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des16", "east",
             "/players/mouzar/castle/high/des25", "south",             
             "/players/mouzar/castle/high/des36", "west",
             "/players/mouzar/castle/high/des27", "north",
         });
             
       }
                if(!present("wdog",this_object())){
                  while(i<5){
                  move_object(clone_object("/players/mouzar/castle/monsters/wdog"),this_object());
                  i=i+1;
                  }
                }
         }
