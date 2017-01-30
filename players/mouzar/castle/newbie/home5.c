 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Miss. Ostgood's House";
long_desc = "Here is a home that was designed and decorated by a woman.  There\n"+
            "are flowers and light colors everywhere.  You can see two halflings\n"+
            "on the floor in front of the fireplace doing umm....\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail34","south",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("ostgood")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/ostgood.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("tuck")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/tuck.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
