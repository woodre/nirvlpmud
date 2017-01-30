 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "glowing fungus onthe walls.  As you enter you step in something\n" +
           "and it doesn't smell good.  It is lizard shit!!  Before you wipe\n" +
           "foot you are attacked by a giant lizard.\n";
          
dest_dir = ({
            "/players/mouzar/castle/mid/cave39","southwest",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("lizard")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/lizard.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
