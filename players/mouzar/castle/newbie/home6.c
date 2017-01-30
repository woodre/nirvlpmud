 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "The Newter Home";
long_desc = "This house is in perfect order.  Nothing is out of place. I mean\n"+
            "nothing is out of place.  You look around and Mr. and Mrs. Newter\n"+
            "belong here.  They are sitting on the couch perfectly strait.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail35","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("newter")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/newter.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("wife")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/newterwife.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
