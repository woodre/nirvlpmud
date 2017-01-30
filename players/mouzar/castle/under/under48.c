inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "Here you see nothing of change here.  There in a T intersection coming up to\n"+
              "north.  You hear a roar come from the south somewhere.  It is silent to the\n"+  
              "north.  There is no wind blowing here but you can feel a chill run down your\n"+ 
              "spine.  The temperature here is cold and damp.  There is little sign of life\n"+ 
              "in this part of the tunnel.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under49","north",
               "/players/mouzar/castle/under/under46","south",
               });
           }
 
} 
