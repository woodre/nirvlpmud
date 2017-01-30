#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("floyd")) {
  move_object(clone_object("/players/francesco/2001/mobs/floyd.c"),
	this_object());  }
set_light(1);

short_desc = "The Moon" ;
long_desc =
     "   MOON,  YEAR 2001\n"+
     "The desolated landscape of the Moon is filled with some dust and \n"+
     "rocks.  At the horizon the Earth can be seen.  The low gravity \n"+
     "definately produces a sense of general well-being.  The movements \n"+
     "are slower yet very gracious. In the far northeast a monolith can\n"+
     "barely be seen.\n",

items = ({
   "dust","It is a dark grey powder, like the sand of those ferrous beachs",
   "rocks", "There are of various sizes and shapes, once upon a time they \n"+
            "were a nice souvenir for the terrestrians",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
   "monolith","The Monolith is not easy to see from here, being too far away",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon10.c","south",
  "/players/francesco/2001/rooms/moon11.c","west",
  "/players/francesco/2001/rooms/moon13.c","north",
});

}
