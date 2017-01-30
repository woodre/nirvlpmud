inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  Oh shit you just ran into a pack of lions!\n";
 
  dest_dir = ({
               "/players/mouzar/castle/high/des60", "south",
               "/players/mouzar/castle/high/des61", "north",
               "/players/mouzar/castle/high/des61", "west",
               "/players/mouzar/castle/high/des51", "east",
         });
             
       }
                if(!present("giant",this_object())){
                  while(i<5){
                  move_object(clone_object("/players/mouzar/castle/monsters/lion"),this_object());
                  i=i+1;
                  }
                }
     }
