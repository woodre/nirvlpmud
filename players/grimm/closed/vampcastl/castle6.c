inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Hall";
long_desc="As you wonder down the hall you notice rooms to the left and\n"+
          "right of you.  Futher down the hallway you can see a very large, \n"+
          "white room with music coming from it.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle9","north",
   "players/grimm/closed/vampcastl/castle10","south",
   "players/grimm/closed/vampcastl/castle11","east",
   "players/grimm/closed/vampcastl/castle3","west"});
set_light(1);
}
