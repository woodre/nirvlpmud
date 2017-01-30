inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "The Fletchery";
long_desc = "This is a rather new home.  It is comfortable, if not ostentatious.\n"+
            "It is crowded with arrows both finished and unfinished.  There is little\n"+
            "furniture here because the couple that lives here is just starting out.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail33","north",
                      });
           }       }
monster() {
int count;
object monster;
 
if(!present("sass")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/sass.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("wally")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/wally.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
 
