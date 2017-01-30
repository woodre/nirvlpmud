 
 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Mayor's Small Mansion";
long_desc = "This is a lovely little place.  Has many wonders here.  You see\n" +
            "the mayor and her handsome husband.  They make a lovely pair.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/trail16","east",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("husband")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/husband.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
if(!present("mayor")) {
while(i<1) {
  monster = clone_object("/players/mouzar/castle/monsters/mayor.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
