#define NQC room

inherit "room/room";

reset(arg) {
   while(!present("rand_pooh 3")) move_object(clone_object("/players/llew/Toys/monsters/rand_pooh"),this_object());
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    Splashed with scenes of the Hundred Acre Woods, this\n"+
      "section is ripe with children living thier fantasies with\n"+
      "the friends therein.  Stories of humor and love come to life\n"+
      "next to the stuffed animals and childrens laughter.  A girl\n"+
      "bounces her favorite character high into the air, catching\n"+
      "it with her welcoming arms.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle13","north",
      "/players/llew/Toys/rooms/aisle22","east",
      "/players/llew/Toys/rooms/aisle33","south",
   });
   items=({
      "girl",
         "The girl laughs as she reaches high to keep the animal close",
   });
}

