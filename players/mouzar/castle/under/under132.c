inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "This part of the tunnel is kinda noisy.  There seems to be cheering comeing\n"+
              "from the east.  There is a community of some kinda there also.  Life in this\n"+
              "lifeless place.  Friend or foe, it makes no difference cause you are going\n"+
              "mad in the silence of this evil place.\n";
   dest_dir = ({
               "/players/mouzar/castle/under/under131","east",
               });
           }
 
  if(!present("duergar")) {
    move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
    move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
  }
}
