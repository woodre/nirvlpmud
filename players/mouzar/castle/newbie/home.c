inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Sheriff Greenspan's Home";
long_desc = "You have entered the home of Sheriff Greenspan.  He and his wife\n" +
            "and their six children live here in harmony.  He has done a good \n" +
            "job keeping the peace here.  Please don't make his job hard.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail17","west",
            "/players/mouzar/castle/newbie/homer","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("wife")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/wife.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("sheriff")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/sheriff.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
