inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is some mumbling\n" +
              "coming from the north.  You can hear feet dragging and heavy footsteps.\n" +
              "There are no sounds coming from anywhere.  You hear your footstep\n"+ 
              "echoing on the walls.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under114","north",
               "/players/mouzar/castle/under/under118","south",
               });
  
           }
if(!present("orc")) {
  move_object(clone_object("/players/mouzar/castle/under/mon/orc"),this_object());
  move_object(clone_object("/players/mouzar/castle/under/mon/orc"),this_object());
  move_object(clone_object("/players/mouzar/castle/under/mon/orc"),this_object());
  move_object(clone_object("/players/mouzar/castle/under/mon/orc"),this_object());
} 
}
 
