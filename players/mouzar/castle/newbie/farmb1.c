 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Bandawax Farm";
long_desc = "Dull looking home with very little valuables hanging round.\n"+
            "Just by looking around you can tell these are some tight Halflings.\n"+
            "They look like a mean Halflings.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail23","north",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("wife")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/gamwife.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("gammer")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/gammer.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
