inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Hall";
long_desc="You have entered the castle of Malachi.  It seems that the entire\n"+
   "castle is very dark from here, as if who ever lives here hates light.\n"+ 
   "The hallway continues east and a short hallway also leads off to the\n"+
   "north.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle4","north",
   "players/grimm/closed/vampcastl/castle5","south",
   "players/grimm/closed/vampcastl/castle6","east",
   "players/grimm/closed/vampcastl/castle2","west"});
set_light(1);
}
