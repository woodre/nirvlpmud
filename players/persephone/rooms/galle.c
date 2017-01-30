#include "/players/persephone/rooms.h"
inherit "/players/persephone/closed/thingys.c";
reset (arg){
  if(!present("mate")){
    move_object(clone_object("players/persephone/monster/mate"), TOB);
  }
 if (!arg) {
  set_light(0);
  short_desc="Pirates Galleon";
  long_desc="This Galleon looks like it is straight of an Errol Flynn movie however\n" +
            "you could be wrong. At first sight this Galleon looks sort of cool\n" +
            "but the longer you stay here the greater your sense of foreboding.\n" +
            "As you glance around you notice that way up in the crows nest there\n" +
           "appears to be some sort of watcher and don't look know but a Pirate has\n" +
           "spied you. Perhaps you should try to run.\n";
  items=({"Flynn","Errol Flynn is not here",
          "watcher","You can only just see the watcher you cannot make\n" +
                    "out what he is doing but definately he is gazing\n" +
                    "at the town",
          "pirate","The pirate is definately not happy to see you as\n" +
                   "swings his cutlass at you",
         });
  dest_dir=({"players/persephone/rooms/pier2b","disembark",
             "players/persephone/rooms/crnestl","up",
             "players/persephone/rooms/galle2.c","south",
  });
 }
}
realm(){ return "NT"; }
init(){
  ::init();
    add_action("south","south");
    add_action("south","s");
}
south(){
  if(!present("womblestart",TPL)){
    write("You feel to much fear to proceed South!!!\n");
  return 1;
  }
}
