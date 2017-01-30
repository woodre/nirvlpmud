#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "   The aisle is flooding with children racing to see thier\n"+
      "favorite hero and to bring their fantasies close to hand.\n"+
      "Action figures of every sort line the wall of the aisle,\n"+
      "boasting their heroic poses and abilities, advertizing \n"+
      "what makes just this one, more valuable.  A child argues\n"+
      "playfully with a younger brother why his favorite is the\n"+
      "one to save the world.  A superhero flies in the hands of\n"+
      "an eager one on his way to more feats of his own creation.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle21","north",
      "/players/llew/Toys/rooms/aisle32","west",
      "/players/llew/Toys/rooms/aisle41","south",
   });
   items=({
      "boy",
         "The boy speaks with his older and wiser voice of \n"+
         "more valiant deeds performed by his superhero",
      "figures",
         "The grinning sur heros will certainly save a learning\n"+
         "childs imagination",
   });
}

