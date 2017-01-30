 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A pasture";
long_desc = "Here you can see several cows grazing in the pasture.  There are\n" +
            "more cows grazing to the south.  You can see the back door of the\n"+ 
            "farmhouse to the west.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/pasture4","south",
            "/players/mouzar/castle/newbie/farma1","west",
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
}
 
