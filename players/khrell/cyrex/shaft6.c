inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(0);
  short_desc = "Turbo shaft6";
  long_desc = 
   "   A dark shaft that seems to go on and on...\n";
  dest_dir = ({"/players/cyrex/shaft5", "up",
               "/players/cyrex/shaft7", "down"});
  }
}
