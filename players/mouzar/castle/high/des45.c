inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "An oasis in a HOT desert";
long_desc = "You have entered an oasis!  THERE IS WATER HERE!  You soak up some of the\n"+
            "shade that is provided by the palm trees.  You are walking on grass instead\n"+
            "of sand for a change.  You can take some of that sand out of your boots if\n"+
            "want.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des44", "south",
             "/players/mouzar/castle/high/des46", "north",
             "/players/mouzar/castle/high/des55", "west",
             "/players/mouzar/castle/high/des35", "east",
         });
             
       }
     
                if(!present("monkey",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/monkey"),this_object());
                  i=i+1;
                  }
                }
         }
 
 
