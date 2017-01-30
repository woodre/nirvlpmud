inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "To the west you see the tunnel turns into a T intersection.  You can hear\n"+
              "sounds coming from that direction.  To the east it is quiet.  There is no\n"+
              "wind blowing here but you can feel a chill run down your spine.  The \n"+
              "temperature here is cold and damp.  There is little sign of life in\n"+
              "this part of the tunnel.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under40","west",
               "/players/mouzar/castle/under/under44","east",
               });
           }
}
 
