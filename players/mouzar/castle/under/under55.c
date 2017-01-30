inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "It is very quiet here.  You can hear yourself breathing along with the sound\n"+
              "of your steps.  There is some noise coming from the east.  It sounds like\n"+
              "rocks sliding against each other.  Do you want to check it out?\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under54","west",
               "/players/mouzar/castle/under/under56","east",
               });
           }
 
} 
