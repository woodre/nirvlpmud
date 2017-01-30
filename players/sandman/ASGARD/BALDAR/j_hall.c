inherit "room/room";

init() {
   ::init();
   add_action("sit","sit");
   add_action("press","press");
}

sit(str) {
   if(str == "on throne") {
      write("\nYou sit on the jeweled throne.\n");
      write("\nYou notice a small button on the arm of the chair.\n");
      write("Maybe you should 'press button'?\n");
      say(this_player()->query_real_name() + " sits on the throne.\n");
      return 1;
   }
}

press(str) {
   if(str == "button") {
      write("\nYou press the button, and the chair spins around in a\n");
      write("circle, you find yourself in a hidden room!\n");
      say(this_player()->query_real_name() + " disappears!\n");
      call_other(this_player(), "move_player",
                "disappear#players/sandman/ASGARD/BALDAR/study");
      return 1;
   }
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Baldar's Throne Room");
   long_desc=
     "This is a long marble hall. Towering columns line the sides of the\n"
+    "room. Torches flicker in sockets on each column, and sitting at the\n"
+    "back of the room is a golden throne.\n";
   items=
   ({
     "throne","A magestic golden throne, maybe try 'sit on throne' ",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/BALDAR/gym","down",
   });
}
