 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A deep cave";
long_desc = "As you enter, you get a strange sensation that you are not\n" +
           "alone. Perhaps it could be all those hornets that are suddenly so\n" +
           "interested in you...\n";
          
dest_dir = ({
           "/players/mouzar/castle/inter","northeast",
            "/players/mouzar/castle/mid/cave2","east",
                      });
           }
       }
 
 
monster() {
int count;
object creature;
 
if(!present("hornet")) {
 while(i<3) {
    creature = clone_object("/players/mouzar/castle/monsters/hornet.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
