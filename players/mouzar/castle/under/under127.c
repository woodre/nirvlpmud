inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "This cave has been made into a guard house.  There are bunks lining the\n"+
              "the walls.  There are even dead bodys in this part of the cave.  Good\n"+
              "the Drow got here first cause there are alot on bunks here.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under41","north",
               });
           }
 
if(!present("duergar")) {
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
} 
}
