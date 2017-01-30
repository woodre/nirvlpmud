inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(0);
  short_desc = "Turbo shaft7";
  long_desc = 
   "   A dark shaft that seems to go on and on...\n";
  dest_dir = ({"/players/cyrex/shaft6", "up",
               "/players/cyrex/shaft8", "down"});
  }
}
