inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Gwynedd";
   long_desc="The entrance to Llew's forest.  It is now a bare\n"+
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
      "/players/llew/Celts/rooms/for_road2.c","west",
      "/players/llew/Celts/rooms/for_road5.c","east",
   });
   }
}
