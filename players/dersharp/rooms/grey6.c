inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="University Street";
   long_desc ="To the east you see a park where it seems people congregate.\n"+
              "This area is surprisingly clean in contrast to what you have\n"+
              "seen in other areas of the city.  There are a couple of trees\n"+
              "here to brighten the place.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey5.c", "west",
             "players/dersharp/rooms/grey7.c", "east",
   });
   items = ({
          "tree", "This tree is young and isn't climbable.",
           });
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<2) {
      creature = clone_object("players/dersharp/monsters/student");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
