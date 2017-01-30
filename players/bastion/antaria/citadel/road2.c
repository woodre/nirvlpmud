inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Eldritch Road";
  long_desc = 
   "You are on a cobble-stoned road. A house stands to the west left while\n" +
   "a store of some kind to the east. A small, and somewhat dusty, flower\n" +
   "garden lies to the side of the road in front of the dwelling.\n";
  items = ({"shop",
             "You see a variety of items for sale in the windows",
            "road",
            "Real cobble-stones! You also note a sign post which reads \"" +
            "Eldritch\nRoad\"",
            "garden",
            "You see some pansies and marigolds",
            "palace",
            "It seems to be the focus of the city"});
  dest_dir = ({"players/bastion/antaria/citadel/road3", "north",
               "players/bastion/antaria/citadel/shop", "east",
               "players/bastion/antaria/citadel/road1", "south",
});
  }
}
