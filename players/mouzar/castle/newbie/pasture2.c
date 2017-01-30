 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A pasture";
long_desc = "Here you can see several cows grazing in the pasture.  You can\n" +
            "see more cows to the north.  There is a trail to the west of\n" +
            "you and past that you can see a farm house.\n";
          
dest_dir = ({
          "/players/mouzar/castle/newbie/trail8","west",
          "/players/mouzar/castle/newbie/pasture1","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("cow")) {
while(i<6) {
  monster = clone_object("/players/mouzar/castle/monsters/cow.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
