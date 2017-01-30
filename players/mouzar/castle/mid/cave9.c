 
inherit"/room/room";
reset(arg) {
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "glowing fungus on the walls.  You have no since of direction\n" + 
           "in these caves.\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave7","west",
           "/players/mouzar/castle/mid/cave10","east",
                      });
           }
       }
 
