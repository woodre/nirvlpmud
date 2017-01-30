inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "It isn't all that quiet here.  You can hear yourself breathing along with the\n"+ 
              "sound of your steps.  In the dim light you don't see a rock and you end up\n"+
              "kicking it down the tunnel.  It makes so much noise that you pause to see if it\n"+ 
		"attracted any unwanted attention.\n";
  dest_dir = ({"/players/mouzar/castle/under/under49","west",
               "/players/mouzar/castle/under/under55","east",
               });
           }
 
} 
