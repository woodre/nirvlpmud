inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Stair Well";
long_desc="This is a stairwell leading to the second level of the castle.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle10","north",
   "players/grimm/closed/vampcastl/castle14","up"});
set_light(1);
}
