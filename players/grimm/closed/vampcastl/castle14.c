inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Upper Stairwell";
long_desc="This is a stairwell that leads to the lower level of the castle.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle16","south",
           "players/grimm/closed/vampcastl/castle15","east",
           "players/grimm/closed/vampcastl/castle13","down"});
set_light(1);
}
