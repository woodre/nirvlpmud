inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="A back hallway";
long_desc="This is a back hallway, to the north is a door to the walk-in\n" +
"freezer. The hallway continues to the east.\n";

dest_dir=({ "players/emerson/rooms/room23.c", "east",
              "players/emerson/rooms/room29.c", "west",
     "players/emerson/rooms/freezer.c", "north",
});

   }
}
