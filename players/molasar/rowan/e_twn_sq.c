

#include "/room/clean.c"

reset(arg) {
   if(!arg)
     set_light(1);
}

id(str) { return str == "statue" || str == "flowers" || str == "flower"; }

short() { return "Eastern side of the Town Square  [n,s,e,w]"; }

long(str) {
 if(str == "statue") { 
  write("A large marble statue stretches over eight feet into the sky.\n");
  write("The figure portrayed by the statue is clad heavily in platemail\n");
  write("armor and is wielding a great broadsword pointed to the south.\n");
  write("A plaque at the base of the statue reads:\n");
  write("    All Hail The Defender Of Rowan, Mordrake\n");
  write("    Slayer of the Dragon, Bringer of Peace\n");
  return 1;
 }
 if(str == "flowers" || str == "flower") {
  write("A large bed of the different types of flowers that cover the\n");
  write("land are positioned around the base of the statue.\n");
  return 1;
 }
 write("You are on the eastern side of the Town Square of Rowan.\n");
 write("The floor of the square is made up of reddish-black cobblestones.\n");
 write("A huge statue stands prominently in the center of the square,\n");
 write("surrounded by a well-kept arrangement of flowers. To the north\n");
 write("lies the general store, to the south the town hall. The famous\n");
 write("sparring arena of Rowan can be seen to the southeast\n");
 write("The square continues to the west.\n");
 write("   There are five obvious exits:  north, south, east, west, and "+
       "southeast\n");
 write("A large statue is here.\n");
}

init() {
   add_action("north","north");
   add_action("south","south");
   add_action("east","east");
   add_action("west","west");
   add_action("southeast","southeast");
}

north() {
   this_player()->move_player("for the General store"+
       "#players/molasar/rowan/shop");
   return 1;
}

south() { 
   this_player()->move_player("south towards the Town Hall"+
       "#players/molasar/rowan/twn_hall");
   return 1;
}

east() {
   this_player()->move_player("the Town Square#players/molasar/rowan/road2");
   return 1;
}

west() {
   this_player()->move_player("for the western side of the Town Square"+
       "#players/molasar/rowan/w_twn_sq");
   return 1;
}

southeast() {
   write("The Sparring room has been closed for repairs.\n\n-Sandman\n");
   return 1;
}


