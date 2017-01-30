#define NQC room

inherit "room/room";

reset(arg) {
   if(!present("joe_sergeant")) move_object(clone_object("/players/llew/Toys/monsters/joe_sergeant"),this_object());
   while(!present("rand_gijoe 2")) move_object(clone_object("/players/llew/Toys/monsters/rand_gijoe"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The coveted action figure, GI Joe, bravely marches the\n"+
      "length of the wall.  Vehicles of military might run along\n"+
      "at the coaxing of little hands, pressing them on with their\n"+
      "laughter and merriment.  What boy can resist the fanstastic\n"+
      "victory of thier troops fighting curageously along side them.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle33","west",
      "/players/llew/Toys/rooms/aisle31","east",
   });
   items=({
      "joe",
         "The famous GI Joe dressed in divergent military uniforms\n"+
         "salute in their plastic coated cases",
   });
}

