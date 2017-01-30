inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(0);
  short_desc = "Turbo shaft2";
  long_desc = 
   "   A dark shaft that seems to go on and on...\n";
  dest_dir = ({"/players/cyrex/shaft", "up",
               "/players/cyrex/shaft3", "down"});
  }
}
