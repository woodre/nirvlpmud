 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A rocky path";
long_desc ="As you walk out of the cave you are blinded by the sunlight.\n" + 
           "This is a rocky path heading west of some dark mountains.  You\n" +
           "can hear the wild animals calling to each other.  Are they\n" +
           "planning to get together to kill you?\n" ;
          
dest_dir = ({
            "/players/mouzar/castle/inter","east",
           "/players/mouzar/castle/path2", "west",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("goat")) {
while(i<3) {
  monster = clone_object("/players/mouzar/castle/monsters/goat.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
