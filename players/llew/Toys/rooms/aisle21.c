#define NQC room

inherit "room/room";

reset(arg) {
   while(!present("rand_teddy 2")) move_object(clone_object("/players/llew/Toys/monsters/rand_teddy"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Delightful cheers of pleasure rage from the aisle, \n"+
      "where a new friend is made in a giant stuffed bear.  The\n"+
      "companions and confidants most loved by all pile high \n"+
      "thier cuddly warmth.  A child nearby squeezes a brown\n"+
      "teddy with fluffy ears, and you can feel the joy shining\n"+
      "brightly from her face.  A mountain of furry animals\n"+
      "tumbles down to rest in the middle of the floor, but no\n"+
      "one gives notice, skipping and careening with laughter,\n"+
      "they carry on their merry-making.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle31","south",
      "/players/llew/Toys/rooms/aisle11","north",
      "/players/llew/Toys/rooms/aisle22","west",
   });
   items=({
      "bear",
         "The bear is a lovable bundle of warmth, most\n"+
         "definitely deserving of a great big hug",
      "girl",
         "Now inseperable from the new found friend, pity goes\n"+
         "to the parent that should refuse the gift she's found",
      "teddy",
         "The brown teddy bear cuddles close to the girl, \n"+
         "as if knowing it will be a treasured companion",
      "animals",
         "Stuffed animals of all sorts are jumbled together in\n"+
         "a mess of fluff and warmth",
   });
}

