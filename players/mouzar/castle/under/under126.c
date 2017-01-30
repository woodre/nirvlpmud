inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Slut's Home";
  long_desc = "This cave has been made into a house of some kind.  There is a big bed\n"+
              "in the center of the room and curtains covering the door way so no one\n"+
              "can see in.  This room seem to be missed by the battle that took place\n"+
              "outside.  It is wierd looking in here.  There are no real words to describe\n"+
              "what this room looks like.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under122","south",
               });
           }
 
if(!present("slut")) 
move_object(clone_object("/players/mouzar/castle/under/mon/duslut"),this_object());
} 
