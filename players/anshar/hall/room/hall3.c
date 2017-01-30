
inherit "room/room";
int X;

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="     The torches reflect from more of those full suits\n"+
            "of armour. There is a passage north that is shadowed and\n"+
            "darkly gloomy. Some noises can be heard from up ahead.\n"+
            "Lining the walls are trophies of battle, hung high in\n"+
            "honored placement. More torches light the way.\n";
  items=({
    "shadows", "Nothing can be seen beyond",
    "trophies", "Weapons and armor from vanquished foes",
    "passage",  "It is impossible to penetrate the gloom",
    "suits",    "Full suits of armour stand rigidly at attention",
    "armour",   "Full suits of armour stand rigidly at attention",
    "torches",  "Ordinary torches save the fact they let off no heat",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall5", "north",
    "/players/anshar/hall/room/hall2", "east",
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
           this_player()->move_player("north#/players/anshar/hall/room/hall5");
           return 1; 
}

