inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Eldritch Road";
  long_desc = 
   "You are on a cobble-stoned road. Nearby, a high wall and gates surrounds\n"+
   "a complex of buildings to the north. The sounds of hammering and\n" +
   "hissing come from the west. An alley leads east.\n";
  items = ({"shop",
             "You see weapons and armor through the window",
            "road",
            "Real cobble-stones! You also note a sign post which reads \"" +
            "Eldritch\nRoad\"",
            "alley",
            "It is rather narrow",
            "complex",
            "It seems to be the focus of the city"});
  dest_dir = ({"players/bastion/antaria/citadel/guild", "north",
               "players/bastion/antaria/citadel/road2", "south",
               "players/bastion/antaria/citadel/smithy", "west"});
  }
}
