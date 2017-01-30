 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(0);
short_desc = "A dark cave";
long_desc = "You enter this warm and dry cave.  It is hard to see things in here.\n"+
            "as you walk along the cave take a sharp turn to the north.\n" ;
dest_dir = ({
             "/players/mouzar/castle/inter","west",
             "/players/mouzar/castle/path10","north",
                      });
           }
       }
 
