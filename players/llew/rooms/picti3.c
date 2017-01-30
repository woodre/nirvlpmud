inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Blood Soaked Battlefield";
   long_desc="The entrance to Llew's forest.  It is now a bare\n"+
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
      "/players/llew/rooms/picti5.c","north",
      "/players/llew/rooms/picti4.c","east",
      "/players/llew/rooms/picti1.c","south",
      "/players/llew/rooms/picti2.c","west",
   });
   }
}
