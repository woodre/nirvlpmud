inherit	"room/room";

reset(arg) { 
  if(!arg) {
set_light(0);
  short_desc = "The Cellar";
  long_desc = 
   "This is a small area that used to serve as a dungeon.  Now it is an empty wine\n"+
   "cellar.  It is pretty dark and damp in here.\n";
   dest_dir = ({"/players/fred/mages/rooms/advance", "up"});
  }
}
