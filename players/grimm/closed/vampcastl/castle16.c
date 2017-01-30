inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Hall";
long_desc="This is a dark hallway leading north and south.  As you look\n"+
          "to the south you sense a great evil, the intensity of this \n"+
          "evil is something that you could never have even imagined!\n";
dest_dir=({"players/grimm/closed/vampcastl/castle14","north",
   "players/grimm/closed/vampcastl/castle17","south"});
set_light(1);
}
