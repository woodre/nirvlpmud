
int latched;

id(str) { return str == "elftree" || str == "tree"; }

short() { return "A tree"; }

long() {
   write("An exceptionally large tree.  The branches are too high up\n");
   write("for you to climb, but if you had some way to get a rope up\n");
   write("to one of the branches maybe you climb the rope.\n");
}

init() {
   add_action("up","up");
   add_action("up","climb");
}

up() {
   if(!latched) {
     write("The branches are too far apart for you to climb.\n");
     return 1;
   }
   this_player()->move_player("up the tree#players/molasar/FOREST/UPPER/entry");
   return 1;
}

set_latched(l) { latched = l; }

query_latched() { return latched; }

