#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("play-doh man")) move_object(clone_object("/players/llew/Toys/monsters/playdoh_man"),this_object());
   while(!present("rand_playdoh 4")) move_object(clone_object("/players/llew/Toys/monsters/rand_playdoh"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The children sit down in this section of the store\n"+
      "letting thier talents of imagination take shape in the\n"+
      "form of Play-Doh.  The multitude of colorful shades \n"+
      "blend together creating creatures and beings of wild\n"+
      "form.  \n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle51","north",
      "/players/llew/Toys/rooms/aisle62","west",
   });
   items=({
      "children",
         "The children squish their makings together with no\n"+
         "remorse ready to make new ones",
      "play-doh",
         "The magical substance that brings the artists out\n"+
         "of the children",
   });
}

