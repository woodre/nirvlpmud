inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "Here you see nothing of change here.  Just an east and west tunnel.  There\n"+
              "is little here that seem of intrest to the normal person or to the untrained\n"+  
              "eye.  There is no wind blowing here but you can feel a chill run down your\n"+ 
              "spine.  The temperature here is cold and damp.  There is little sign of life\n"+ 
              "in this part of the tunnel.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under46","north",
               "/players/mouzar/castle/under/under44","west",
               });
           }
 
} 
