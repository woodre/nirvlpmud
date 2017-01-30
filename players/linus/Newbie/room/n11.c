#include "/players/linus/def.h"
inherit "/room/room.c";
  reset(arg){
   if(!present("pooh", TO)) {
   MO(CO("/players/linus/Newbie/NPC/Pooh.c"),TO);
}
   if(!present("piglet", TO)) {
   MO(CO("/players/linus/Newbie/NPC/Piglet.c"),TO);
}
    set_light(1);
    short_desc = GRN+"The hundred acre wood"+NORM;
    long_desc = GRN+
"Empty honey pots lay scattered around the base of a large tree,\n"+
"which stands to the east of a dirt footpath.  A log lies to the side\n"+
"of a wooden door, which is built into the tree.  A board above the\n"+
"door has the words 'Mr Sanders' written on it, and a small bell hangs\n"+
"to the left of the door.  A small piece of paper which reads 'Rnig\n"+
"also' is nailed to the tree beneath the bell.\n"+NORM;
    items = ({
           "tree","A large maple tree.  There is a door built into it",
           "door","A wooden door with a small metal handle.  It appears to be locked",
           "handle","A small metal handle fixed to the door",
           "log","A small log that is laying on the ground",
           "honey pots","Empty honey pots that lay around",
           "pots","Empty honey pots that lay around",
           "pot","An empty honey pot",
           "board","A weathered board with some writing on it.  You could probably 'read' it",
           "bell","A small metal bell that has been tarnished with age",
           "paper","A piece of paper nailed to the tree that has some writing on it",
           "footpath","Brown dirt where grass will no longer grow",
           "path","Brown dirt where grass will no longer grow",
});
     dest_dir = ({ 
          NEWB+"n12.c","north",
          NEWB+"n10.c","west"  });
}
init() {
    ::init();
    add_action("ring_bell","ring");
    add_action("read_stuff","read");
    add_action("Listen","listen");
}
ring_bell(string str) {
        if(!str || str!="bell") { FAIL("Ring what?\n"); return 0; }
        if(str=="bell") {
           write(TPN+" rings the bell.  Dong! dong! dong!\n");
           say(TPN+" rings the bell.  Dong! dong! dong!\n");
    return 1;
 }
}
read_stuff(str) {
   if(!str) { FAIL("Read what?\n"); return 0; }
 switch(str) {
   case "board": write("The board has the words 'Mr. Sanders' written on it.\n"); return 1;
   case "paper": write("The paper has the words 'Rnig Also' written on it.\n"); return 1;
   default: FAIL("Read what?\n"); return 0;
}
}
Listen() {
 write("The chirping songs of birds from within the forest can be heard.\n");
 return 1;
}
