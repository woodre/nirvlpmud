#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("quest_cabbage")) move_object(clone_object("/players/llew/Toys/monsters/quest_cabbage"),this_object());
   while(!present("rand_cabbage 3")) move_object(clone_object("/players/llew/Toys/monsters/rand_cabbage"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The thronging children show thier eager need to be off \n"+
      "down the aisles in search of adventure.  Parents barely \n"+
      "hold the children in rein, each one trying to bound away\n"+
      "as fast as their little feet can carry them.  Here a girl\n"+
      "sits down happily playing with the dolls on display fore-\n"+
      "telling what she wants her life to be when she grows up.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle31","north",
      "/players/llew/Toys/rooms/aisle42","west",
      "/players/llew/Toys/rooms/entrance","east",
      "/players/llew/Toys/rooms/aisle51","south",
   });
   items=({
      "children",
         "The children pull anxiously at the riengs of thier parents\n"+
         "hands unwilling to waste a second of precious fun in the store",
      "parents",
         "Holding on to the last bit of control, the parents await\n"+
         "the chaos soon to come",
      "dolls",
         "Small replicas of little girls and boys, a splended\n"+
         "tool of fantasy",
      "girl",
         "Imagining her life to be a happy wonderful, the girl\n"+
         "sternly speaks to the doll in her childish wisdom",
   });
}

