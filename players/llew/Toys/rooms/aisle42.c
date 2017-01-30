#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("barbie")) move_object(clone_object("/players/llew/Toys/monsters/barbie"),this_object());
   if(!present("ken_doll")) move_object(clone_object("/players/llew/Toys/monsters/ken.c"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The most famous and popular doll resides in this section\n"+
      "lining the walls with new styles and outfits, Barbie, a \n"+
      "model of perfection for little girl's dreams.  A girl places\n"+
      "the dolls in a house, pretending the fantasy life of the\n"+
      "dolls she considers real.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle43","west",
      "/players/llew/Toys/rooms/aisle41","east",
   });
   items=({
      "girl",
         "Living in the house herself with the stylish dolls,\n"+
         "the girl places them in precise position",
      "house",
         "A great mansion for the dolls to make their fantasy",
   });
}

