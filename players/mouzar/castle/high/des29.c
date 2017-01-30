inherit"/room/room";
int i;
 
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "As you enter the area one sound sticks out from the rest.  It is hissing\n"+
            "of two large snakes.  They are not happy to see you.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des19", "east",
             "/players/mouzar/castle/high/des28", "south",             
             "/players/mouzar/castle/high/des39", "west",
             "/players/mouzar/castle/high/des30", "north",
         });
             
       }
                if(!present("snake",this_object())){
                  while(i<2){
                  move_object(clone_object("/players/mouzar/castle/monsters/snake"),this_object());
                  i=i+1;
                  }
                }
         }
