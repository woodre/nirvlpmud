 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Jallisall's farmhouse";
long_desc = "You enter the farmhouse of three brothers.  They are three wacky\n" +
            "halflings.  As you look around the room, you can see that this\n" +
            "hasn't had the pleasure of a woman's touch.  There are three lonely\n" +
            "halflings.  The place is very dirty and and has this smell.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail8","east",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("larry")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/larry.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("curly")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/curly.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("moe")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/moe.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
