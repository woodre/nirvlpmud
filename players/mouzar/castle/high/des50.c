inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?\n";
 
  dest_dir = ({
               "/players/mouzar/castle/high/des49", "south",
               "/players/mouzar/castle/high/des51", "north",
               "/players/mouzar/castle/high/des60", "west",
               "/players/mouzar/castle/high/des40", "east",
         });
             
       }
                if(!present("maskhi",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/maskhi"),this_object());
                  i=i+1;
                  }
                }
     }
