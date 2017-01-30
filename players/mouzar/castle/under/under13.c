inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "The tunnel here is long and very quiet.  You can hear you foot steps echo\n"+
               "off the walls around you.  You are the only thing that is moving in this\n"+
               "part of the tunnel or so it seems.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under14","west",
               "/players/mouzar/castle/under/under12","east",
               });
           }
 
} 
