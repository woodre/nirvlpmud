 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "glowing fungus on the walls.  You suddenly notice two extra shadowsws\n" +
           "in the room.\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave49","southeast",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("shadow")) {
 while(i<2) {
    creature = clone_object("/players/mouzar/castle/monsters/shadow.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
