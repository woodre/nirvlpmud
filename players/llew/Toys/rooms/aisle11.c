#define NQC room

inherit "room/room";

reset(arg) {
   mon_reset();
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The northern border of the grand store is crawling with\n"+
      "more enthusiastic children, bustling through the aisle of\n"+
      "the legos.  A shout grabs the attention of a lost parent \n"+
      "thought to have gained a slight respite from the grueling\n"+
      "adventure.  Boxes of legoland sets fill far down the aisle\n"+
      "promising years of happiness.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle21","south",
      "/players/llew/Toys/rooms/aisle12","west",
   });
   items=({
      "parent",
         "There is no break for the gaurdian of a childs imagination",
      "child",
         "A look of utter joy caresses the cheering child, having\n"+
         "found that one set of legos that would make his set the best",
      "legos",
         "The greatest construction set of all time, the \n"+
         "legos are the best at bringing forth imaginative\n"+
         "creations",
   });
}

mon_reset() {
   if(!present("police_legoman")) move_object(clone_object("/players/llew/Toys/monsters/legoman_police"),this_object());
   while(!present("rand_legoman 2")) move_object(clone_object("/players/llew/Toys/monsters/legoman"),this_object());
}
