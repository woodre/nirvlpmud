 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A cobble stone trail";
long_desc = "To the northwest you can see a small farm.  To the east is a house.\n" +
            "As you walk through town you see two halfling women walking to the\n"+
            "store.  They say their greetings as they pass you.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail20","northwest",
            "/players/mouzar/castle/newbie/trail22","east",
                      });
           }
          }
monster() {
int count;
object monster;
 
if(!present("woman")) {
while(i<2) {
  monster = clone_object("/players/mouzar/castle/monsters/hwoman");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
