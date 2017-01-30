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
     "rocks.  At the horizon the Earth can be seen.  To the north and to\n"+
     "the west the landscape keeps going always the same, to the south\n"+
     "the cupoles of Clavius still can be seen.\n",

items = ({
   "dust","It is a dark grey powder, like the sand of those ferrous beachs",
   "rocks", "There are of various sizes and shapes, once upon a time they \n"+
            "were a nice souvenir for the terrestrians",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
   "cupoles","They are round transparent spheres, about 200 feet tall",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon4.c","southeast",
  "/players/francesco/2001/rooms/moon9.c","west",
  "/players/francesco/2001/rooms/moon6.c","north",
});

}
