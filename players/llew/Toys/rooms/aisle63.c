#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("mr potato head")) move_object(clone_object("/players/llew/Toys/monsters/mr_potato"),this_object());
   if(!present("mrs potato head")) move_object(clone_object("/players/llew/Toys/monsters/mrs_potato"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Body parts are randomly strewn about the area, all\n"+
      "different types of lips and eyes or ears and noses.  \n"+
      "The Potato Head family smiles happily from the shelves\n"+
      "down at the children playing with the overflowing buckets\n"+
      "of parts.  A child shoves a last eye into a potato claiming\n"+
      "a certain resemblance to a parent watching above.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle53","north",
      "/players/llew/Toys/rooms/aisle62","east",
   });
   items=({
      "parts",
         "The eyes and lips, noses, ears, hats, beards and mustaches,\n"+
         "pipes and even arms and legs are jumbled together in the parts",
      "shelves",
         "A potato head stares smilingly",
      "children",
         "The happy children make more faces and poses than could be thought of",
      "child",
         "The child gazes up grinning at he parent he claimed to \n"+
         "have reproduced so magnificently",
      "parent",
         "The potato head certainly does not resemble the parent\n"+
         "whasoever, but who would disappoint the child?",
      "buckets",
         "The buckets contain ever shape of the potato head",
   });
}

