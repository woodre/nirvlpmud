inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc =
"The tall watch tower looms closer now. You can see the flag bearing\n"+
"the standard of Ledsville, a lead dragon wielding a huge, glowing\n"+
"sword, flapping in the breeze at the top.\n";
   dest_dir =
({ 
"players/nightshade/room/castle/castle5", "east",
"players/nightshade/room/castle/castle3", "west",
});
}
