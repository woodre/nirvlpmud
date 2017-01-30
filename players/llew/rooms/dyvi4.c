inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Caer Dyvi";
   long_desc="The entrance to Llew's forest.  It is now a bare\n"+
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
      "/players/llew/rooms/dyvi1.c","north",
      "/players/llew/rooms/dyvi3.c","west",
      "/players/llew/rooms/dyvi5.c","east",
   });
   }
}
