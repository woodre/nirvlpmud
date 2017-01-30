#define NQC room

inherit "room/room";

reset(arg) {
   while(!present("rand_gijoe 2")) move_object(clone_object("/players/llew/Toys/monsters/rand_gijoe"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Whistles of marching tunes fill the air from the\n"+
      "children sounding off to the GI Joe action figures held\n"+
      "respectfully in their hands.  A boy to the side places \n"+
      "his ready troops in rank to go forth in battle and\n"+
      "conquer his imagined foes.  The children jostle each \n"+
      "other unconcernedly laughing their differences away in \n"+
      "the fury of excitement.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle23","north",
      "/players/llew/Toys/rooms/aisle32","east",
      "/players/llew/Toys/rooms/aisle43","south",
   });
   items=({
      "troops",
         "Lined up in perfect form, the troops could defend any \n"+
         "amry dared to be sent against them",
      "boy",
         "Generaling his troops to glory, the boy notices little\n"+
         "of the chaos surrounding his battlfield",
   });
}

