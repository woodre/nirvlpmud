 
inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "Here you can see two camels laying in the sand soaking some rays.\n"+
            "They turn to look at you as you walk up to it.  They are just looking\n"+
            "at you probally wondering what the hell that crazed person is\n"+
            "doing here.  There is a mountain range off the the east.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des9", "south",
             "/players/mouzar/castle/high/des20", "west",
             "/players/mouzar/castle/high/des11", "north",
         });
             
       }
                if(!present("camel",this_object())){
                  while(i<2){
                  move_object(clone_object("/players/mouzar/castle/monsters/camel"),this_object());
                  i=i+1;
                  }
                }
         }
