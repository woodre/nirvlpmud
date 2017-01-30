inherit "players/nightshade/new_room";
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Castle wall";
   long_desc = 
"The wall continues east towards a large watch tower. A tall, strong\n"+
"looking guard starts walking towards you. As you peer over the wall\n"+
"you can see a pedler trying to sell his wares from a large wagon.\n";
   dest_dir =
({
   "/players/nightshade/room/castle/castle4", "east",
   "/players/nightshade/room/castle/castle2", "west",
});
}
