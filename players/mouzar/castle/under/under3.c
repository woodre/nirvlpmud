 
inherit"/room/room";
int i;
reset(arg) {
monster();
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is this smell\n" +
              "that just makes you want to puke.  It is the smell of rotting bodies.\n" +
              "You can't tell where it is coming from.  This tunnel goes off into\n"+
              "two different directions.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under2","west",
               "/players/mouzar/castle/under/under4","east",
               });
           }
} 
monster() {
int count;
object monster;
 
if(!present("zombie")) {
while(i<4) {
  monster = clone_object("/players/mouzar/castle/under/mon/zombie");
  move_object(monster, this_object());
i++;
}
i=0;
}
}
