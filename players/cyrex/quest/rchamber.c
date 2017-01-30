inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "Sub-Chamber";
  long_desc = 
   "This is the chamber where life and all other things are created. The\n"+
   "Robotech Masters usually keep this room sparkling clean, but somehow\n"+
   "there are gadgets and papers scattered all about. It looks like if\n"+
   "some terrible battle had taken place in here. You see some stairs here\n"+
   "leading up to another brightly lit chamber.\n";
  dest_dir = ({"players/cyrex/tunnel", "portal",
               "players/cyrex/quest/mchamber", "up"});
  }
}
