inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is this smell\n" +
              "that just makes you want to puke.  It is the smell of rotting bodies.\n" +
              "You can't tell where it is coming from.  This tunnel goes off into\n"+
              "two different directions.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under1","north",
               "/players/mouzar/castle/under/under3","east",
               });
           }
} 
