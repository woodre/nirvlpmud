inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Tunnel";
  long_desc = "This cave is barren.  The rock on the Northern wall looks loose.  There\n"+
              "are huge, four toed foot prints leading into the Northern wall.  There\n"+
              "is a stinch in this cave.  Smells like rotting flesh.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under56","north"});
           }
  if(!present("umberhulk")) { 
    move_object(clone_object("/players/mouzar/castle/under/mon/hulk"),this_object());
  }
} 
