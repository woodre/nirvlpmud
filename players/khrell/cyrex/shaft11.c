inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(0);
  short_desc = "Turbo shaft11";
  long_desc = 
   "   Finally you have reached the bottom of the shaft. You look up and\n"+
   "see nothing but total blackness. The gusts of winds continue to pound\n"+
   "on your face. There is something very wierd about this shaft. You wonder\n"+
   "where it continues now.\n";
  no_exits = 1;
  dest_dir = ({"/players/cyrex/shaft10", "up",
               "/players/cyrex/Etunnel", "east"});
  }
}
