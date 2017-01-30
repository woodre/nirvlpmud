inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Inside Gate";
  long_desc = 
   "You stand inside the great gates of the Wizards' Citadel. Doors lead into\n"+
   "the gatehouse on either side. Merchants bustle along the road with carts\n"+
   "and wagons. Various shops and dwellings line the street ahead, leading to\n"+
   "what looks like a palace.\n";
  items = ({"gate",
            "The tall, bronze gates stand open",
            "merchants",
            "They appear to be in a hurry to deliver their wares",
            "palace",
            "It seems to be the focus of the city",
            "gatehouse",
            "Some guards are milling about the entrances"});
  dest_dir = ({"players/bastion/antaria/citadel/road1", "north",
               "players/bastion/antaria/citadel/gate", "south",
    });
  }
}
