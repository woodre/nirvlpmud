inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "In tower";
   long_desc =
"The inside of the tower is damp and dim. There are arrow slits for\n"+
"royal achers so that they might rain down arrows upon the king's\n"+
"enemies. Two royal archers stand at the ready. \n"+
"There are stairs leading up.\n";
   dest_dir =
({
"players/nightshade/room/castle/castle5", "west",
"players/nightshade/room/castle/castle7", "north",
"players/nightshade/room/castle/tower1", "up",
});
}
