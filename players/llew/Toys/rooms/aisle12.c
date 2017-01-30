#define NQC room

inherit "room/room";

reset(arg) {
   mon_reset();
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Cities and moonbases, castles and fortresses display\n"+
      "their creativity for all to see.  The lego boxes have pieces\n"+
      "and designs for anything you could think of, all but that\n"+
      "a child could think of.  A single child, oblivious to her\n"+
      "surroundings is lost in the land she's created in her mind.\n"+
      "A joyful smile graces her cute dimpled cheeks as she giggles\n"+
      "merrily.  \n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle13","west",
      "/players/llew/Toys/rooms/aisle11","east",
   });
   items=({
      "legos",
         "Some few legos brought out to capture the attention of the\n"+
         "children lay sprawled about, ready for another idea of \n"+
         "imagination",
      "girl",
         "Content as can be, the girl looks as if she could\n"+
         "stay in this wonderful forever",
   });
}

mon_reset() {
   while(!present("rand_legoman 3")) move_object(clone_object("/players/llew/Toys/monsters/legoman"),this_object());
}
