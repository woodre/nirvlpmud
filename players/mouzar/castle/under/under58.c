inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is some mumbling\n" +
    "coming from the south.  You can hear feet dragging and heavy footsteps.\n" +
    "You hear your footsteps echoing on the walls.  Wonder if your footsteps will\n"+
    "give you away?\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under114","south",
               "/players/mouzar/castle/under/under56","west",
  });
 
  }
 
}
