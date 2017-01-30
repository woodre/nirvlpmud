#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("hephalump")) move_object(clone_object("/players/llew/Toys/monsters/hephalump"),this_object());
   if(!present("woozle")) move_object(clone_object("/players/llew/Toys/monsters/woozle"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "   The backroom of the toy store is lit by little light\n"+
      "from the outside chaos.  Two swining doors sway gently down\n"+
      "to a restful stop.  The boxes of unpacked toys stack up to\n"+
      "the darkness, hidden from the wild rampaging children. All\n"+
      "is quiet.  The dust is thin, almost non-existent in the \n"+
      "clean store.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle53","east",
   });
   items=({
      "light",
         "The dancing lights from the store beyond enter palely \n"+
         "through the small windows in the swinging doorway",
      "doors",
         "Easily moved, the doors are well oiled and used with the\n"+
         "same care that goes to all the toys placed outside",
      "boxes",
         "Cardboard bundles of toys are compacted tightly in the small\n"+
         "storage space.  Here and there a sign can be seen reading,\n"+
         "\"Made in Taiwan\"",
      "dust",
         "Barely noticable, but still there in the calm of the\n"+
         "backroom, the dust blankets the unpacked boxes",
   });
}

