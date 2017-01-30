inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="A courtesan's room";
   long_desc ="This room's sole purpose is to keep the courtesans of the \n"+
              "amused.  The room is covered with diverse furniture ranging\n"+
              "from pillows to fancy divans.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/hall3.c", "east",
   });
}
init() {
    ::init();
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/dersharp/monsters/courtes");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
