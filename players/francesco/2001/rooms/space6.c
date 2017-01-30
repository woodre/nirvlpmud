#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("russian")) {
  move_object(clone_object("/players/francesco/2001/mobs/russian1.c"),
	this_object());  }
if (!present("russian")) {
  move_object(clone_object("/players/francesco/2001/mobs/russian2.c"),
	this_object());  }
set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "This room is likely an observatory.  Very ample windows allow for\n"+
     "looking at the deep outer space.  Far distant the Earth and the\n"+
     "Moon can be seen.  Few longchairs are randomly positioned in the room \n"+
     "for people to relax and to look at the magnificent sightseeing.\n",

items = ({
   "longchairs","They are made by plastic and metals, yet must be very comfortable",
   "windows","Some rectangular windows, about 6x8 feet wide",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
   "moon","A small sphere at the horizon, undefined grey areas can be seen",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space4.c","down",
});

}
