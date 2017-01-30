
#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

id(str) { return str == "flowers" || str == "flower"; }

short() { return "A large clearing"; }

long(str) {
  if(str == "flowers" || str == "flower") {
    write("Flowers from all over the realm are spread out before you.\n");
    write("Some you recognize, others are completely alien to you in\n");
    write("appearance and smell.\n");
    return 1;
  }
  write("The clearing has been landscaped to a perfection urivaled in the\n");
  write("realm of Nirvana. You feel at peace looking at the huge beds\n");
  write("of flowers which cover almost every inch of space. The aroma\n");
  write("is so intoxicating, you feel as if you have no earthly cares.\n"); 
  write("Five stone paths lead off to the south, southeast, southwest, east,\n");
  write("and west.\n");
  write("There are six obvious exits: north, south, southeast, southwest,\n");
  write("east and west\n");
}

init() {
   add_action("north","north");
   add_action("east","east");
   add_action("west","west");
   add_action("south","south");
   add_action("southeast","southeast");
   add_action("southwest","southwest");
}

southeast() {
   this_player()->move_player("southeast#players/molasar/rowan/castle4");
   return 1;
}

southwest() {
   this_player()->move_player("southwest#players/molasar/rowan/castle5");
   return 1;
}

north() {
   this_player()->move_player("north#players/molasar/rowan/road3");
   return 1;
}

south() {
   this_player()->move_player("south#players/molasar/rowan/castle2");
   return 1;
}

east() {
   this_player()->move_player("east#players/molasar/rowan/castle1");
   return 1;
}

west() {
   this_player()->move_player("west#players/molasar/rowan/castle3");
   return 1;
}


