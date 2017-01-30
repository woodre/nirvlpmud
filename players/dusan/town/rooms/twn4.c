#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
set_light(1);

short_desc = "Muddy Trail.";
long_desc =	
           "   A few small bushes dot the side of this muddy trail.    \n"+
           "A faint murmur drifts in from the large log building to  \n"+
           "east.  A sign hangs from the building, and a soft murmur \n"+
           "can be heard.  To the north leads back to the main road.  \n" ;

items = ({
  "road","A muddy road that leads through the town",
  "trail","A trail of muddy earth that leads to the east",
  "sign","A large wooden sign hanging from the building depicting a tankard of ale",
  "tankard","A picture of a large cup of ale on the sign",
  "murmur","A soft sound drifts from the building to the east",
  "mud","A dark brown mud that makes up most of the road",
  "building","A stout log building to the east",
  "bushes","Small scraggly bushes that seem to be struggling",
});

dest_dir = ({
  "/players/dusan/town/rooms/twn2","north",
  "/players/dusan/town/rooms/pub","east",
});

}
