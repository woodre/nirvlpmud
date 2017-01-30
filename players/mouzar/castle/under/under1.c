inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is a smell\n" +
              "that just makes you want to puke.  It is the smell of rotting bodies.\n" +
              "You can't tell where it is coming from.  This tunnel goes off into\n"+
              "three different directions.\n" ;
  dest_dir = ({
               "/players/mouzar/castle/under/under2","south",
		"/players/mouzar/castle/under/under39","west",
               "/players/mouzar/castle/mid/cave4","up",
               });
           }
} 
