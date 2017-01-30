inherit	"room/room";

reset(arg) { 
 if(!present("Spring")) {
   move_object(clone_object("players/zone/obj/spring.c"), this_object());
 }
  if(!arg) {
  set_light(1);
  short_desc = "Spring";
  long_desc = 
   "There is a spring basin here.  It seems a nice, peaceful spot to\n"+
   "refresh yourself.\n";
  items = ({"spring",
            "This is the source of the brook.  There is a small basin\nwhere cool clear refreshing water wells up."});
  dest_dir = ({"players/zone/rooms/brook2.c", "north"});
  }
}
