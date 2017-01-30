inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="A back hallway";
long_desc="This is a back hallway, to the north is a there seems to be\n" +
   "something big and slimy.\n";

dest_dir=({ "players/emerson/rooms/room24.c", "east",
              "players/emerson/rooms/break.c", "west",
     "players/emerson/rooms/room30.c", "north",
});

   }
}
