inherit "room/room";
int i;

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
     if(!present("tree")) {
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
   if(!arg) {
      set_light(1);
       short_desc="A small clearing [w]";
       long_desc=
       "This is a small peacefull clearing in the center of which is a\n"+
       "large fallen log. Perfect to sit on. The only thing marring the\n"+
       "beauty of the clearing is the dark forboding trees surrounding it\n";
      dest_dir=
      ({
        "players/sandman/ASGARD/EVIL/dpath4", "west"
      });
   }
}
