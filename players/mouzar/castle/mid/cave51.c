 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "glowing fungus on the walls.  There is a large spider climbing the\n" +
           "walls.  It's web takes up most of the room here so don't get \n" +
           "in it or you will be the next meal.\n";
          
dest_dir = ({
            "/players/mouzar/castle/mid/cave49","east",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("myrlochar")) {
 while (i<1) {
   creature = clone_object("/players/mouzar/castle/monsters/myrlochar.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
