 
inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "A HOT desert";
long_desc = "As you walk in you realize that you have made a mistake.  There\n"+
            "is a giant scorpion turning to face you and he doesn't look happy.\n"+
            "His tail is in striking position.  You better make a move.  You\n"+
            "can run or fight like a true adventurer\n";
 
dest_dir = ({
             "/players/mouzar/castle/high/des12", "south",
             "/players/mouzar/castle/high/des14", "north",
             "/players/mouzar/castle/high/des23", "west",
             "/players/mouzar/castle/high/des3", "east",
         });
             
       }
                if(!present("scorpion",this_object())){
                  while(i<1){
                  move_object(clone_object("/players/mouzar/castle/monsters/scorpion"),this_object());
                  i=i+1;
                  }
                }
         }
