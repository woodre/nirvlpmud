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
     "This centrifuge room rotates around the hub link.  It is part\n"+
     "of a round, endless aisle which is shaped like a ring with a\n"+
     "circumference of about two miles.  Mainly used for making jogging \n"+
     "under plain gravity conditions, it is the best solution for \n"+
     "maintaining the physical fitness of the spacecraft crew during\n"+
     "long term interplanetary voyages.\n",

items = ({
   "hub","The center of the spacecraft",
   "link","The center of the spacecraft",
   "hub link","The center of the spacecraft",
});

dest_dir = ({
  "/players/francesco/2001/rooms/discovery2.c","southeast",
  "/players/francesco/2001/rooms/discovery12.c","northwest",
});

}
