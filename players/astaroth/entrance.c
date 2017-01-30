inherit	"room/room";

reset(arg) { 
  if(!arg) {
  set_light(1);
  short_desc = "A large entrance hall";
  long_desc = 
   "You have entered the castle of Astaroth.\n"+
   "Astaroth would like you to have fun, explore, and check out the\n"+
   "hot tub in the good music section.  The full range of monsters\n"+
   "are not yet available, and they probably won't be until finals\n"+
   "are over for Astaroth.  One word of warning, don't even try to\n"+
   "attack Stuart Hamm unless you are at a really high level.  He's\n"+
   "worth a lot, but he's also VERY tough.\n"+
   "\n";
  dest_dir = ({"players/astaroth/junct", "north",
               "/room/big_tree", "south"});
  }
}
