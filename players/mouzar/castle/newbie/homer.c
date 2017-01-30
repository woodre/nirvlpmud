 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "Kids room";
long_desc = "Sheriff Greenspan's kids are at play in there room.  They look\n"+
            "like some well behaved kids.  The room is a nice size but when\n"+
            "six kids are stuffed into one room is better be big.\n";
          
dest_dir = ({
            "/players/mouzar/castle/newbie/home.c","south",
                      });
           }
       }
monster() {
int count;
object monster;
 
if(!present("kid")) {
while(i<6) {
  monster = clone_object("/players/mouzar/castle/monsters/kid1.c");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
 
