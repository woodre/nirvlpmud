inherit "room/room";
int i;
reset(arg) {
  monster();
   if (arg) return;
   short_desc="University Street";
   long_desc ="The gates to the Citadel lie closed to the west.  The \n"+
              "guards here look very formidable and even after getting\n"+
              "rid of them, you would still have to find a way past \n"+
              "the gates.  As you stand here you notice a foul odor \n"+
              "coming from a drainage ditch.\n";
   set_light(1);
   dest_dir =
   ({
             "players/dersharp/rooms/grey1", "east",
   });
   items = ({
          "gate", "This gate looks very strong and there doesn't seem\n"+
                  "to be a lock on it...too bad.",
         "ditch", "This ditch looks worn with age and use, along one side\n"+
                  "of it you see an entrance of some kind..............\n"+
                  "maybe you should try to ENTER.."
           });
}
init() {
    ::init();
    add_action ("Enter", "enter");
}
Enter() {
     say (this_player()->query_name() + " enters the ditch...YUCK!\n");
     write ("You enter the drainage ditch carefully.\n");
     move_object(this_player(), "players/dersharp/rooms/sub0.c");
     return 1;
}
monster() {
int count;
   object creature;
   if(!present("creature")) {
    while (i<3) {
      creature = clone_object("players/dersharp/monsters/citguard");
      move_object(creature, this_object());
     i++;
       }
    i = 0;
   }
}
