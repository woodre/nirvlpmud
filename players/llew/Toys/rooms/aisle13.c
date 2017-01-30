#define NQC room

inherit "room/room";

reset(arg) {
   mon_reset();
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    In this farthest reaches of the toy store, there is \n"+
      "still no lack of happy children running rampant to gain\n"+
"their favorite toys.  Here grabbing what calls to each\n"+
      "of their fancies, the legos that give the most freedom\n"+
      "in creativity.  Even there, a parent sits down with a\n"+
      "helpless grin playing fervently with the legos, sharing\n"+
      "and trading pieces with a child next to them.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle12","east",
      "/players/llew/Toys/rooms/aisle23","south",
   });
   items=({
      "legos",
         "The toys cherished by many generations of children\n"+
         "hungry for an outlet to thier imagination",
      "parent",
         "What a wonder the parent makes sitting down there, \n"+
         "living memories of past adventures.  Were it possible\n"+
         "that we could never grow up and stay so happy",
   });
}

mon_reset() {
   if(!present("captain")) move_object(clone_object("/players/llew/Toys/monsters/lego_captain"),this_object());
   while(!present("rand_pirate 4")) move_object(clone_object("/players/llew/Toys/monsters/lego_pirate"),this_object());
}
