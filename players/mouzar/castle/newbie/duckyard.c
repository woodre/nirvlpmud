 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A duckyard";
long_desc = "This is a duckyard full of ducks.  Your boots will never be the same\n" +
            "There are some fat ducks.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail9","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("duck")) {
while(i<7) {
  monster = clone_object("/players/mouzar/castle/monsters/duck.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 

