 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Candlemaker's Place";
long_desc = "Here you find an old bitchy Halfling woman.  She seems to complain\n"+
           "about EVERYTHING.  She starts yelling about your ugly face as soon as\n"+
           "you walk in the door.  This place reminds you of your grandmother's house.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail39","south",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("carissa")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/carissa.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
