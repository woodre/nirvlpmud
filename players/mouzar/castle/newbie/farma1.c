 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "The Kalliwart Farm";
long_desc = "When you enter you can see two elderly Halflings.  This house\n"+
           "smells like your grandmothers house.  You see that Blythi is cooking\n"+
           "something on the small stove in the corner of the room.  You can\n"+
           "see cows and chickens out in the back.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/pasture3","east",
           "/players/mouzar/castle/newbie/trail19","west",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("blythi")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/blythi.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("glenvius")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/glenvius.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
