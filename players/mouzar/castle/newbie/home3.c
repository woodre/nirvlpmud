 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Poor Man Trill's Home";
long_desc = "This shake is owned by the gambler of the village.  He has wasted\n"+
            "all his money gambling it away.  He sulks in a corner holding a\n"+
            "bottle of ale.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail24","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("trill")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/trill.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
