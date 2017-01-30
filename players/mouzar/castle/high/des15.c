 
inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "As you enter you see a pack of jackles eating a corpse of some\n"+
            "poor animal that couldn't run away from pack.  Looks like they just\n"+
            "finished eating.  Lets hope you can get away.\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des14", "south",
             "/players/mouzar/castle/high/des16", "north",
             "/players/mouzar/castle/high/des25", "west",
             "/players/mouzar/castle/high/des5", "east",
         });
             
       }
                if(!present("jackle",this_object())){
                  while(i<5){
                  move_object(clone_object("/players/mouzar/castle/monsters/jackle"),this_object());
                  i=i+1;
                  }
                }
         }
