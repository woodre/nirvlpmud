 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "Walking around this cave you see some crab looking things.  They\n" +
        "are eating what looks like a short humanoid creature.  Watch yourself\n" +
        "...you could be next.\n";
         
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave9","west",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("fisher")) {
 while (i<2) {
    creature = clone_object("/players/mouzar/castle/monsters/fisher.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
