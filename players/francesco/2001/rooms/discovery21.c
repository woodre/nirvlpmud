#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Discovery" ;
long_desc =
     "   DISCOVERY SPACECRAFT,  1,000,000 MILES FROM EARTH\n"+
     "This room is still part of the endless aisle from which the most\n"+
     "of the spacecraft is made.  It also has a connection to the hub\n"+
     "of the spacecraft.  The hub is located to the south and can be \n"+
     "accessed through a tube-shaped aisle.\n",

items = ({
   "hub","The center of the spacecraft",
   "aisle","It is a tube leading to the hub of the spacecraft",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery7.c","east",
  "/players/francesco/2001/rooms/discovery19.c","south",
  "/players/francesco/2001/rooms/discovery6.c","west",
});

}
