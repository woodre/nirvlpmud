 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Woodcarver's Shop";
long_desc = "In here you can see wood carveings all over the room.  You can see\n"+
            "little toys, firgurines, and objects laying around.  The old\n"+
            "Halfling here is a master carver.  He can make the loveliest\n"+
            "things with a knife and a piece of wood.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail27","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("batel")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/batel.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
