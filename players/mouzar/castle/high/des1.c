 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
 
set_light(1);
short_desc = "Side of a Mountain";
long_desc = "As you walk out to the side of the moutain you are blinded by\n"+
            "the hot sun.  You have entered a desert!  It is hard to see far\n"+
            "cause of the heat waves coming off the ground.\n";
 
dest_dir = ({
             "/players/mouzar/castle/path11", "east",
             "/players/mouzar/castle/high/des6", "west",
         });
             
       }
     
         }
