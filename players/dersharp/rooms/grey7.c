inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="Juncture";
   long_desc ="To the south here is Short Street.  To the east and north of\n"+
              "here is the university where great minds from all over Oerth\n"+
              "come to spend too much money for an education..sound famaliar?\n"+
              "This three-way intersection is the start of the park proper.\n"+
              "Trees rise up gently and continue to the north.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey6.c", "west",
             "players/dersharp/rooms/grey11.c", "south",
             "players/dersharp/rooms/grey8.c", "east",
   });
   items = ({
          "tree", "These trees are bigger than the ones to the south and west\n"+
                  ", but are still too small for climbing.",
           });
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/dersharp/monsters/student");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
