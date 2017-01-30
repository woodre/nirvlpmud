inherit "room/room";

init() {
   ::init();
   add_action("read","read");
   add_action("ring","ring");
}

read(str) {
   if(str == "sign") {
   cat("/players/sandman/ASGARD/BALDAR/SIGN1");
   return 1;
   }
}

ring(str) {
   object monster;
   if(str == "bell") {
      if(present("giant")) {
        write("Gaint says: You must fight me first mortal!\n");
        return 1;
      }
      monster = clone_object("players/sandman/MONSTERS/giant");
      move_object(monster, this_object());
      write("From out of nowhere a giant appears to spar with you.\n");
      return 1;
   }
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("a gym [u,d]");
   long_desc=
     "This is a large circular room. The walls and floor are padded with\n"
+    "large mats. A SIGN hangs on one wall. Hanging in the center of the\n"
+    "room is a small bell.\n";
   items=
   ({
     "sign","This is a large sign, perhaps you should 'read sign'",
     "bell","A small brass bell, perhaps you should 'ring bell'",
   });
   dest_dir=
   ({
     "players/sandman/ASGARD/BALDAR/entrance","down",
     "players/sandman/ASGARD/BALDAR/j_hall","up",
   });
}
