inherit"/room/room";
int i;
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Drow House";
  long_desc = "You have entered a broken down house.  This might have been a famous\n"+
            "and spectular house but fell from the favor of the Spider Queen and\n"+
            "was destroyed to prove to the other houses what happens to houses\n"+
          "that fall from the grace of the Spider Queen.\n";
  dest_dir = ({"/players/mouzar/castle/under/under24","east",
               });
           }
if(!present("slave"))
move_object(clone_object("/players/mouzar/castle/under/mon/sldrow"),this_object());
} 
