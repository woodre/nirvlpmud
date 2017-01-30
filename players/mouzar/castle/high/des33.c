inherit"/room/room";
int i;
 
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "As you track through this endless sea of sand you see a humanoid coming up.\n"+
            "When you get closer he greats you warmly and asks if you are lost.  This guy\n"+
            "This guy is bald, muscular, and has long finger nails.  He has a very wicked\n"+
            "grin?\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des23", "east",
             "/players/mouzar/castle/high/des32", "south",             
             "/players/mouzar/castle/high/des43", "west",
             "/players/mouzar/castle/high/des34", "north",
         });
             
       }
                if(!present("dao",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/dao"),this_object());
                  i=i+1;
                  }
                }
         }
