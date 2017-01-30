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
     "This corridor connecting different areas of Clavius is almost a tube.\n"+
     "Made by transparent materials it allows to see the Earth and the \n"+
     "neighbourings of Clavius.  The low gravity definately produces a sense\n"+
     "of general well-being. The movements are slower yet very gracious.\n",

items = ({
   "dust","It is a dark grey powder, like the sand of those ferrous beachs",
   "rocks", "There are of various sizes and shapes, once upon a time they \n"+
            "were a nice souvenir for the terrestrians",
   "earth","It looks a sphere at the horizon, with the brown and the blue \n"+
           "colors of the seas and of the grounds.  The white of the clouds\n"+
           "is visible as well",
   "neighbourings","A desolated land, made by dust and rocks",
});

dest_dir = ({
  "/players/francesco/2001/rooms/moon3.c","west",
  "/players/francesco/2001/rooms/moon1.c","southeast",
  "/players/francesco/2001/rooms/moon10.c","northwest",
});

}
