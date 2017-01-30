 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "The Baldorf Home";
long_desc = "The nicely kept house of the Baldorfs.  They live alone in this\n"+
            "small but lovely home.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail20","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("daldorf")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/daldorf.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("wife")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/daldwife.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
