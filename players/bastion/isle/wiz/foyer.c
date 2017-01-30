inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Foyer";
  long_desc = 
   "This is the foyer of the manor. Candles burn in sconces set into the\n"+
   "panelling. A large door leads north, while two smaller ones open\n"+
   "east and west. The main door is to the south.\n";
  items = ({"candles",
            "The candles burn but do not diminish"});
  dest_dir = ({"players/bastion/isle/wiz/stair1", "north",
               "players/bastion/isle/wiz/guards", "east",
               "players/bastion/isle/wiz/entrance", "south",
               "players/bastion/isle/wiz/front_clst", "west"});
  }
}
