 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Halfling Daycare";
long_desc = "You have entered the Halfling daycare center.  It isn't that crowded\n"+
            "for some reason.  No one can find out what is happening to the\n"+
            "kids of this village.  There is no one watching the kids right\n"+
            "now so they are running loose.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail37","south",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("child")) {
while(i<4) {
  monster = clone_object("/players/mouzar/castle/monsters/child2.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
