 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave is darker that the others.  You can see a large cape\n" +
            "hanging in the corner.  Wait did it just move?  You hear a moan\n" +
            "come from the cloak as it turn and attacks you.  You get the chills\n" +
            "as you hear it moan.\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave25","south",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("cloaker")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/cloaker.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
