 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Locksmith's Porch";
long_desc = "You walk up the steps onto the porch and you find everything locked\n"+
            "up tight.  Looks like no one is home.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail30","east",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("dog")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/dog.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
