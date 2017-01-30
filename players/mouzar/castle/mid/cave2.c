 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A clearing amongst the stalactites";
long_desc = "This clearing seems to have been made into a homestead of some\n"  +
            "sort. Litter is strewn all over the place, as well as the bones\n" +
           "various adventurers and ex-girlfriends.  Eeeeeewwwwww.....\n";
          
dest_dir = ({
             "/players/mouzar/castle/mid/cave1b","north",
             "/players/mouzar/castle/mid/cave1","west",
                      });
           }
       }
 
 
monster() {
int count;
object creature;
 
if(!present("thaggypoo")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/thaggy.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 
