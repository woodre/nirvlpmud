
inherit "room/room";
int X;

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="     The torches reflect from more of those full suits\n"+
            "of armour, from the entrance. The passage north shows\n"+
            "signs of recent use, and is darkly shadowed. Some noises\n"+
            "can be heard from ahead. Lining the walls are trophies of\n"+
            "battles long forgotten. More torches flicker high on the\n"+
            "walls, causing shadows to flicker\n";
  items=({
    "shadows", "Nothing can be seen beyond",
    "trophies", "Weapons and armor from vanquished foes",
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall6", "north",
    "/players/anshar/hall/room/hall2", "west",
  });
}
init() {
   ::init();
   add_action("north","north");

   }

  north() {
           if(X==0) { 
           move_object(clone_object("/players/anshar/hall/mon/armour"),this_object());
           move_object(clone_object("/players/anshar/hall/mon/armour"),this_object());
           move_object(clone_object("/players/anshar/hall/mon/armour"),this_object());
           move_object(clone_object("/players/anshar/hall/mon/armour"),this_object());
           write("Moving north, you hear a scraping behind just as four forms barrel into you.\n"); 
           say("The suits of armour leap to attack "+this_player()->query_name()+".\n");
           present("armour",this_object())->attack_object(this_player());
           X++;
           return 1; }
           if(X==1 && present("armour")) { 
           write("The armour stands in your way.\n"); 
           say("The suit of armour prevents "+this_player()->query_name()+" from going north.\n");
           present("armour",this_object())->attack_object(this_player());
           return 1; }
           this_player()->move_player("north#/players/anshar/hall/room/hall6");
           return 1; 
}

