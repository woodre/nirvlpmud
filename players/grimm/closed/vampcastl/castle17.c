inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Bedroom Entrance";
long_desc="You have come to the entrance of a bedroom.  The evil you have\n"+
          "felt definately is eminating from the inside!\n";
dest_dir=({"players/grimm/closed/vampcastl/castle16","north",
   "players/grimm/closed/vampcastl/castle18","east"});
set_light(1);
}
