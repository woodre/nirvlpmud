inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Duergar Home";
  long_desc = "This is a Duergar home.  There is little room in there but there is a\n"+
              "of chairs and a bed in here.  It doesn't have alot of riches in it but\n"+
              "it might make a comfortable home (for a Duergar).\n" ;
  dest_dir = ({"/players/mouzar/castle/under/under133","west",
               });
           }
if(!present("husband"))
  move_object(clone_object("/players/mouzar/castle/under/mon/duhusband"),this_object());
if(!present("wife"))
  move_object(clone_object("/players/mouzar/castle/under/mon/duwife"),this_object());
}
