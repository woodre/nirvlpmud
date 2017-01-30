inherit "room/room";
realm() { return "NT"; }
reset(arg) {
if(arg)
   return;
short_desc="Castle Hall";
long_desc="As you enter the hallway you notice a disgusting smell coming\n"+
          "from the north.\n";
dest_dir=({"players/grimm/closed/vampcastl/castle7","north",
   "players/grimm/closed/vampcastl/castle3","south"});
set_light(1);
}
