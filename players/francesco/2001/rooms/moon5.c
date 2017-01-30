#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "The Moon" ;
long_desc =
     "   MOON,  YEAR 2001\n"+
     "The desolated landscape of the Moon is filled with some dust and \n"+
     "rocks. At the horizon the Earth can be seen.  The low gravity \n"+
     "definately produces a sense of general well-being.  The movements \n"+
     "are slower yet very gracious.\n",

items = ({
   "dust","It is a dark grey powder, like the sand of those ferrous beachs",
   "rocks", "There are of various sizes and shapes, once upon a time they \n"+
            "were a nice souvenir for the terrestrians",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon12.c","south",
  "/players/francesco/2001/rooms/moon14.c","east",
  "/players/francesco/2001/rooms/moon15.c","northeast",
});

}
