#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "   Tiny miniature fortresses and cabins line the aisle\n"+
      "made from little logs of wood piled to heights by small\n"+
      "builders.  The Lincoln Logs are spread wide across the \n"+
      "floor manipulated deftly by the great children architects.\n"+
      "Slanted roofs and chimneys rise from the building spaced\n"+
      "along this section of the store.  \n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle63","west",
      "/players/llew/Toys/rooms/aisle61","east",
   });
   items=({
      "logs",
         "The dark brown wooden logs are cut for easy handling\n"+
         "and building by the creative minds of the children",
   });
}

