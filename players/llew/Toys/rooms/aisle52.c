#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Things";
   long_desc=
      "    Children race by, zipping along next to the cars \n"+
      "screeching across the floor.  From fire engines to \n"+
      "speedy racing cars, the Matchbox and Hot Wheels toys\n"+
      "fill the children with excitement.  Parents jump quickly\n"+
      "out of the way of the makeshift speedway and cardboard\n"+
      "ramps hurdling the vehicles along.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle53","west",
      "/players/llew/Toys/rooms/aisle51","east",
   });
   items=({
      "children",
         "The mock drivers speed their race cars along the raceway",
      "cars",
         "The Matchbox and Hot Wheels that make collections \n"+
         "and collectors, shine metallicly from the dancing\n"+
         "light above",
      "parents",
         "Fond memories return of their own collections as a child",
      "ramps",
         "The cardboard ramps lift the metal racers airborne",
   });
}

