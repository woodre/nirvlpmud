inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc = 
"The wall continues west. About halfway down you see aa short figure\n"+
"standing looking over the wall into a small forest. The forest comes\n"+
"almost right up to wall and is rather thick so it could probably hide\n"+
"a great number of things.\n";
dest_dir =
({ 
"players/nightshade/room/castle/castle13", "west",
"players/nightshade/room/castle/castle11", "east",
});
}
