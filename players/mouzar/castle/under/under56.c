inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is some rumbling\n" +
    "coming from the south.  There are really no other sounds around here.  You hear\n"+
    "your footsteps echoing on the walls.  Wonder if your footsteps will give you away?\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under57","south",
               "/players/mouzar/castle/under/under55","west",
               "/players/mouzar/castle/under/under58","east",
  });
 
  }
 
}
