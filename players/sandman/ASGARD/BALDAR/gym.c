/*
Changes:
  Limited the quantity of frost giants that can be summoned.
  -Feldegast 1/26/01
*/
inherit "room/room";

int count;

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
      if(count > 4) {
        write("Nothing happens.\n");
        return 1;
     }
      if(present("giant")) {
        write("Giant says: You must fight me first mortal!\n");
        return 1;
      }
      monster = clone_object("players/sandman/MONSTERS/giant");
      move_object(monster, this_object());
      write("From out of nowhere a giant appears to spar with you.\n");
      count++;
      return 1;
   }
}
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=("Baldar's gym");
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
