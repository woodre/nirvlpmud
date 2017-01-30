 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Dale's bakery";
long_desc = "You are hit by the scent of fresh baked bread as you enter.  You\n" +
            "see an old well rounded halfling putting some bread out to selll.\n" +
            "You see two of dottery's grandchildren playing in the corner.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail11","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("child")) {
while(i<2) {
  monster = clone_object("/players/mouzar/castle/monsters/child1.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("dottery")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/dottery.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
