#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("Winnie the Pooh")) move_object(clone_object("/players/llew/Toys/monsters/pooh"),this_object());
   while(!present("rand_pooh 2")) move_object(clone_object("/players/llew/Toys/monsters/rand_pooh.c"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Mounds of giant stuffed animals pile high upon\n"+
      "the floor send out their atmosphere of softness, rivaled\n"+
      "only by the mounds of children holding and loving them \n"+
      "with all their might.  Here a love is born to last a\n"+
      "lifetime with the fondness of unconditional friendship\n"+
      "found in a stuffed animal.  The children laugh with \n"+
      "unbridled gaity and emotion at thier parents, returning\n"+
      "proud smiles.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle23","west",
      "/players/llew/Toys/rooms/aisle21","east",
   });
   items=({
      "animals",
         "   What pleasant warmth comes from holding a loved\n"+
         "animal spreads its cheer to each child around",
      "parents",
         "Gazing back with loving pride at the happiness \n"+
         "they've brought into this world, there's no denying\n"+
         "the children a new friend in the animals",
   });
}

