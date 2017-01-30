inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is some mumbling\n" +
              "coming from the south.  You can hear feet dragging and heavy footsteps.\n" +
              "There are no sounds coming from anywhere.  You hear your footsteps\n"+ 
              "echoing on the walls.  Wonder if your footsteps will give you away?\n" ;
  dest_dir = ({
		"/players/mouzar/castle/under/under58","north",
               "/players/mouzar/castle/under/under115","south",
               });
  
           }
}
 
