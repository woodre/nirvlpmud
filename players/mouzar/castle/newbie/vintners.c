inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Daleside Red Vintage";
long_desc = "Here you see a cheerful and robust couple that are playing cards\n"+
            "at the table.  Pally looks as though he is winning.  You can see\n"+
            "wine bottle all around the room.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail27","west",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("pally")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/pally.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("dorith")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/dorith.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
