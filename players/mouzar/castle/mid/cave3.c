 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
            "where you are going.  You can see light coming from south.\n" +
            "Maybe you should make a break for it while you are alive.\n" ;
          
dest_dir = ({
           "/players/mouzar/castle/inter","south",
           "/players/mouzar/castle/mid/cave4","north",
                      });
           }
       }
 
