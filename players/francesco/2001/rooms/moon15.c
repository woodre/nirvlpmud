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
     "rocks.  At the horizon the Earth can still be seen.  To the northeast \n"+
     "lays a monolith.\n",

items = ({
   "dust","It is a dark grey powder, like the sand of those ferrous beachs",
   "rocks", "There are of various sizes and shapes, once upon a time they \n"+
            "were a nice souvenir for the terrestrians",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
   "monolith","The Monolith is not easy to see from here, yet it is possible\n"+
              "to notice its cubic shape",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon16.c","east",
  "/players/francesco/2001/rooms/moon7.c","northeast",
  "/players/francesco/2001/rooms/moon5.c","southwest",
});

}
