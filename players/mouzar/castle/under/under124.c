inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Hospital (Kinda)";
  long_desc = "This area has been made into a rough hospital.  There are some beds and a\n"+
              "desk in here.  Blood covers the floor and the three beds in here.  There\n"+
              "is a feeling of death in here.\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under123","east",
               });
           }
if(!present("healier"))
  move_object(clone_object("/players/mouzar/castle/under/mon/duhealier"),this_object());
} 
