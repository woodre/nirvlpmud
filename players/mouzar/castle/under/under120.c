inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is this smell\n" +
              "that just makes you want to puke.  It is the smell of rottig bodies.\n" +
              "You can't tell where it is coming from.  There are no sounds coming\n"+
              "from anywhere.  You hear your footsteps echoing on the walls.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under121","west",
               "/players/mouzar/castle/under/under119","east",
               });
  
           }
 
}
