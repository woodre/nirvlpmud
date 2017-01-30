 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "You can hear a clamping sound as you enter this cave.  You can make\n" +
            "out a large scorpion like thing.  It turns to face you!!!!\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave27","north",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("scaladar")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/scaladar.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
