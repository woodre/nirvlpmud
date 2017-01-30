inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Eldritch Road";
  long_desc = 
   "You are on a cobble-stoned road. Shops stand on either side of you.\n" +
   "Through the din of city life, the smells of brimstone, food and perfume\n"+
   "assault your nostrils. The road continues north, leading to a large\n" +
   "palatial structure.\n";
  items = ({"shops",
             "One appear to be a tavern, while the other has some mystical\n" +
             "symbols adorning it's facade",
            "road",
            "Real cobble-stones! You also note a sign post which reads \"" +
            "Eldritch\nRoad\"",
            "palace",
            "It seems to be the focus of the city"});
  dest_dir = ({"players/bastion/antaria/citadel/road2", "north",
               "players/bastion/antaria/citadel/pub", "east",
               "players/bastion/antaria/citadel/gate2", "south",
   });
  }
}
