inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(0);
  short_desc = "Turbo shaft";
  long_desc = 
   "   You climbed down and find yourself in a shaft.  Gusty winds blow in\n"+
   "your face.  A howling sound can be heard throughout the shaft.  You wonder\n"+
   "how far it goes down...what if you lose your grip?!\n";
  dest_dir = ({"/players/cyrex/corridor", "up",
               "/players/cyrex/shaft2", "down"});
  }
}
