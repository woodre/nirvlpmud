 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "torchs on the walls.  There is a humoniod playing with a snake.\n" +
           "He turns to you and says hi.\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave44","southwest",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("maedar")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/maedar.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
       
