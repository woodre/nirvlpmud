inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "You have entered a dark and dingy tunnel.  There is this smell\n" +
              "that just makes you want to puke.  It is the smell of rotting bodies.\n" +
              "You can't tell where it is coming from.  There is some strange sounds\n"+
              "coming from all round you.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under4","north",
               "/players/mouzar/castle/under/under6","south",
               });
  move_object(clone_object("/players/mouzar/castle/under/mon/zombie"),this_object());
           }
 
} 
