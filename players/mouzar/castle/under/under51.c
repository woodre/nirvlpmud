inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(0);
  short_desc = "Tunnel";
  long_desc = "It is pitch black in this part.  You see no signs of life in this part\n"+
	      "of the tunnel.  The tunnel goes east and west.  Where will you be safe\n"+
	      "you think?  Maybe you'll never be safe in this place of death.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under52","west",
               "/players/mouzar/castle/under/under50","east",
               });
           }
 
} 
