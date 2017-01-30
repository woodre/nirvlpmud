inherit"/room/room";
reset(arg) {
if(!arg) {
  set_light(1);
  short_desc = "Duergar Town Hall";
  long_desc = "This is the Duergar town hall.  They are throwing a big party for some reason.\n"+
              "You put together that they were able to push back the drow.  There is no care\n"+
              "for the dead cause they died fighting.  A big honor in this community.  There\n"+
              "is beer all over the place.  They are all around on table talking and cheering.\n";
 
  dest_dir = ({"/players/mouzar/castle/under/under129","south",
               });
           }
 
  if(!present("drunk")) {
    move_object(clone_object("/players/mouzar/castle/under/mon/dudrunk"),this_object());
    move_object(clone_object("/players/mouzar/castle/under/mon/dudrunk"),this_object());
    move_object(clone_object("/players/mouzar/castle/under/mon/dudrunk"),this_object());
  if(!present("king"))
    move_object(clone_object("/players/mouzar/castle/under/mon/duking"),this_object());
  }
}
