inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "The tunnel here is long and very quiet.  You can hear your foot steps echo\n"+
               "off the walls around you.  You are the only thing that is moving in this\n"+
               "part of the tunnel or so it seems.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under36","north",
	       "/players/mouzar/castle/under/under35","south",
               "/players/mouzar/castle/under/under33","west",
               });
           }
 
} 
