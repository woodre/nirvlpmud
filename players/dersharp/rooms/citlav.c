inherit "room/room";
reset(arg) {
   if (arg) return;
   short_desc="The lavitory";
   long_desc ="This is a large room with many stalls for the use of the \n"+
              "inhabitants in the Citadel.  At the moment the room is empty\n"+
              ",just be glad you didn't come after dinner....YUCK!\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/sub-1.c", "down",
             "players/dersharp/rooms/hall3.c", "west",
   });
}
