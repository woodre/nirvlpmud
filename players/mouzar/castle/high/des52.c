inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
set_light(1);
short_desc = "A HOT desert";
long_desc = "You are scorched by the hot sun.  You are getting thirsty.  You\n"+
            "start to wonder if this was a good idea.  Are you lost?  Will You\n"+
            "ever get out?  You can help but to notice a GIANT standing above you\n"+
            "getting ready to stab you with that big spear he has.\n";
 
  dest_dir = ({
               "/players/mouzar/castle/high/des52", "south",
               "/players/mouzar/castle/high/des53", "north",
               "/players/mouzar/castle/high/des52", "west",
               "/players/mouzar/castle/high/des42", "east",
         });
             
       }
                if(!present("giant",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/giant"),this_object());
                  i=i+1;
                  }
                }
     }
