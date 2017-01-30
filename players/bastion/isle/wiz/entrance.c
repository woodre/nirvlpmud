inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Entrance";
  long_desc = 
   "You face the outside of a small castle or manor. A double oaken door\n"+
   "stands closed on the granite facade. To the right, you see a tower\n"+
   "rising out of the building topped by a metallic dome. A path leads \n"+
   "back down to the shore.\n";
  items = ({"manor",
            "The manor is as grey as the sea and sky. You notice candles burning in\nthe windows",
            "castle",
            "The manor is as grey as the sea and sky. You notice candles burning in\nthe windows",
            "dome",
            "You notice that the dome is not whole, a slit running from top to bottom\nat one point. A cylindrical device protrudes from the opening",
            "observatory",
            "You notice that the dome is not whole, a slit running from top to bottom\nat one point. A cylindrical device protrudes from the opening"});
  dest_dir = ({"players/bastion/isle/wiz/foyer", "in",
               "players/bastion/isle/wiz/shore2", "south"});
  }
}
