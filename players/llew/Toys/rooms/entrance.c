#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Toys are spread throughout the store in a grand adventure\n"+
      "of the imagination.  The aisles lead to treasures of childhood\n"+
      "dreams and happiness.  The colorful lights above sing of the\n"+
      "gay atmosphere.  Children run the lengths of the overloaded\n"+
      "toy shelves, dragging patient parents along in their gleeful\n"+
      "exuberance.  A counter with a smiling grandfatherly old man\n"+
      "resting behind stands guarding the world of fantasy, where \n"+
      "all senses of joy are welcomed.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle41","west",
      "/room/eastroad4","out",
   });
   items=({
      "toys",
         "The toys beckon you on to explore the aisles",
      "store",
         "S.K. Toys 'n Stuff, the place where dreams come true",
      "lights",
         "Fanciful lights swing from the high cieling dancing\n"+
         "along with the gleeful children",
      "children",
         "Their imaginations in ecstacy, the children couldn't be happier",
      "parent",
         "The patient parent follow thier screaming children with\n"+
         "a forgiving smile and memories of their own youth",
      "counter",
         "The glass display case holds more treasures of fantasy",
      "man",
         "The man with the gray mustache and a contagious smile",
   });
}

