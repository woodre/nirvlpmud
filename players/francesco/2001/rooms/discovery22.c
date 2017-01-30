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
     "This tubolar aisle connects the outer part of the spacecraft to\n"+
     "its hub.  Walking here is easier than in the outer part, mainly\n"+
     "for the reduced effect of the rotational speed.  Going toward the\n"+
     "hub would be even easier.\n",

items = ({
   "hub","The center of the spacecraft",
   "link","The center of the spacecraft",
   "hub link","The center of the spacecraft",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery23.c","east",
  "/players/francesco/2001/rooms/discovery5.c","west",
});

}
