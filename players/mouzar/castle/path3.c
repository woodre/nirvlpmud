 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A rocky path";
long_desc = "This is a rocky path heading west of some dark mountains.  You\n" +
            "can hear the wild animals calling to each other.  Are they\n" +
            "planning to get together to kill you?\n" ;
          
dest_dir = ({
             "/players/mouzar/castle/path2","east",
             "/players/mouzar/castle/newbie/npath1","west",
                      });
           }
       }
 
