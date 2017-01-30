inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="A wide hallway";
   long_desc ="You are travelling along the main corridor of the Citadel\n"+
              "when you hear sounds like somebody laughing coming from the\n"+
              "south.\n";
set_light(1);
dest_dir =
 ({
          "players/dersharp/rooms/hall3.c", "north",
          "players/dersharp/rooms/ante4.c", "east",
          "players/dersharp/rooms/ante3.c", "west",
          "players/dersharp/rooms/hall1.c", "south",
 });
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/dersharp/monsters/lacky");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
