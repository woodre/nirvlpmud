 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A clearing amongst the stalactites";
long_desc = "This is still part of the clearing.  This seems to be a rough\n"+
            "kitchen.  It looks as though Art has kept this place up real\n"+
            "good.  Just like a good wife should.  Art is busy cooking thag's\n"+
            "supper.\n";
          
dest_dir = ({
             "/players/mouzar/castle/mid/cave2","south",
                      });
           }
       }
 
 
monster() {
int count;
object creature;
 
if(!present("art")) {
 while (i<1) {
    creature = clone_object("/players/mouzar/castle/monsters/art.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
