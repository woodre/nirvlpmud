 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A pasture";
long_desc = "Here you can see several cows grazing in the pasture.  There are\n" +
            "more cows grazing to the north.  This is the pasture with the towns\n"+
            "one and only bull.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/pasture3","north",
                      });
           }
          }
monster() {
int count;
object monster;
 
if(!present("cow")) {
while(i<5) {
  monster = clone_object("/players/mouzar/castle/monsters/cow.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("bull")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/bull.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
