inherit"/room/room";
int i;
 
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "Here you see a old female.  She looks very hungry and thirsty.\n"+
            "You have a strange feeling about her.  She looks up at you from\n"+
            "her would be grave if you dont help her.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des27", "east",
             "/players/mouzar/castle/high/des36", "south",             
             "/players/mouzar/castle/high/des47", "west",
             "/players/mouzar/castle/high/des38", "north",
         });
             
       }
                if(!present("silat",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/silat"),this_object());
                  i=i+1;
                  }
                }
         }
