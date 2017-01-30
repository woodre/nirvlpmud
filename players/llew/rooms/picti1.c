inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Hadrian's Wall";
   long_desc="The entrance to Llew's forest.  It is now a bare\n"+
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
      "/players/llew/rooms/for_road2.c","south",
      "/players/llew/rooms/picti3.c","north",
   });
   }
}
