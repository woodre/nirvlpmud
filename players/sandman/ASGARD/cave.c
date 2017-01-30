inherit "room/room";
int one;

init() {
   ::init();
   add_action("free","free");
   add_action("out","out");
}

out() {
   if(present("loki")) {
     write("The most evil of Gods blocks your path!!!\n");
     return 1;
   }
}
free(str) {
   if(str == "girl" && one) {
     if(!present("loki")) {
one--;
       write("As you free the girl, her image shimmers, and seems to change.\n");
       write("\nIn her place is stand, Loki the Deciever!!!\n");
         move_object(clone_object("players/sandman/MONSTERS/loki.c"), this_object());
     }
     return 1;
   }
}
reset(arg) {
   if(!arg) {
      set_light(0);
one = 1;
       short_desc="The bowels of the earth";
       long_desc=
    "This is a deep dank cavern. Stalagtites and stalagmites rise up from\n"
+   "the ceiling and the floor. In the center of the cave is a roughly hewn\n"
+   "alter, upon which a small girl is tied. She pleads for your help,\n"
+   "perhaps you could 'free girl'.\n";
      dest_dir=
      ({
       "players/sandman/ASGARD/mstreet3", "out"
      });
   }
}
