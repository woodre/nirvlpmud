#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Cars zoom down the aisle guided by the hands of the \n"+
      "speeding children.  The Matchbox and Hot Wheel vehicles \n"+
      "crash violently together in mock accidents to the delight\n"+
      "of the laughing children.  Cars dance with the light \n"+
      "playing off the metallic bodies.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle43","north",
      "/players/llew/Toys/rooms/backroom","west",
      "/players/llew/Toys/rooms/aisle52","east",
      "/players/llew/Toys/rooms/aisle63","south",
   });
   items=({
      "cars",
         "Shiny bright new cars of all sorts zip down the aisles",
      "children",
         "The children spin about their racing vehicles",
   });
}

