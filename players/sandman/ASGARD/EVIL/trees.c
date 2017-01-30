inherit "room/room";
int i;
int hh;

init() {
   ::init();
   add_action("sit","sit");
   add_action("west","west");
}

west() {
   if(present("tree")) {
     write("An evil tree blocks your path!!!\n");
     return 1;
   }
}
sit(str) {
   if(str == "on log") {
   if(hh) { write("Nothing happens.\n"); return 1; }
     if(!present("tree")) {
   hh = 1;
       write("You hear a rustling around you, and the creaking of wood.\n");
       for(i=0;i<3;i++) {
         write("A tree uproots itself and moves to block your path!\n");
         move_object(clone_object("players/sandman/MONSTERS/tree.c"), this_object());
       }
     }
     return 1;
   }
}
reset(arg) {
 hh = 0;
   if(!arg) {
      set_light(1);
       short_desc="A small clearing";
       long_desc=
       "This is a small peaceful clearing in the center of which is a\n"+
       "large fallen log. Perfect to sit on. The only thing marring the\n"+
       "beauty of the clearing is the dark foreboding trees surrounding it.\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/EVIL/dpath4", "west"
      });
   }
}
