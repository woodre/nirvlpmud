inherit "room/room";

reset(arg) {
if(!arg) {
   set_light(1);
   short_desc="Forest Clearing";
   long_desc="The entrance to Llew's forest.  It is now a bare\n"+
      "clearing. East to Caer, north to road.\n";
   dest_dir=({
      "/players/llew/rooms/for_road1.c","north",
      "/players/llew/rooms/caerdyvi1.c","west",
   });
   }
}
