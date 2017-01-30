inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Duergar Community";
  long_desc = "As you walk into the part of the tunnel there are signs that a deadly battle\n"+
              "was fought here.  You see dead bodies of Drow and of Duergar.  The Drow bodies\n"+
              "are few but size means nothing when it comes to the Drow.  Apparently the Drow\n"+
              "stumbled upon a settlement of Duergar and decided to have a little fun.  The\n"+
              "song that you hear has to be one for the dead.  Telling the gods how these\n"+
              "Duergar died fighting a deadly enemy.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under127","south",
               "/players/mouzar/castle/under/under122","west",
	       "/players/mouzar/castle/under/under42","east",
               });
           }
 
if(!present("duergar")) {
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
move_object(clone_object("/players/mouzar/castle/under/mon/duguard"),this_object());
}
} 
