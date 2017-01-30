
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="     Obviously, these are the sumptious apartments of some\n"+
            "great battle commander. More trophies of war line the walls\n"+
            "and a full suit of ornamental armour stands upright in one\n"+
            "corner of the room. The fireplace provides the only light\n"+
            "in this dim area. A large bed takes up the center of the\n"+
            "richly carpeted chamber, with a large chest standing at its\n"+
            "foot. To one side is a sitting area with three chairs and a\n"+
            "heavy wooden table. The room has the definite appearance of\n"+
            "being lived in\n";
  items=({
    "suit",     "Of an older, but very functional style, and slightly gilded",
    "armour",   "Of an older, but very functional style, and slightly gilded",
    "armour",   "Full suits of armour stand rigidly at attention",
    "trophies", "Numerous testaments of the room's tenant's prowess in battle",
    "walls",    "Rough cut but well constricted walls",
    "fireplace","A huge fireplace with a roaring flame upon its hearth",
    "bed",      "The thick feather mattress seems to be in good repair",
    "chest",    "A large mahogany chest",
    "chair",    "Rather plain and functional",
    "chairs",   "Rather plain and functional",
    "table",    "Also of mahogany, the chairs ring it",

  });
  dest_dir=({
   "/players/anshar/hall/room/hall9", "south",
   "/players/anshar/hall/room/hall11", "north",
  });
if(!present("terran"))
{
move_object(clone_object("/players/anshar/hall/mon/terran"),this_object());
}
}
init() {
   ::init();
   add_action("south","south");
   add_action("north","north");

   }

  south() {
           if(present("terran")) { 
           write("Terran says: You cannot leave without defeating me.\n"); 
           say(""+this_player()->query_name()+" is prevented from going south.\n");
           return 1; }
           this_player()->move_player("north#/players/anshar/hall/room/hall9");
           return 1; 
}
  north() {
           if(present("terran")) { 
           write("Terran says: You cannot leave without defeating me.\n"); 
           say(""+this_player()->query_name()+" is prevented from going south.\n");
           return 1; }
           this_player()->move_player("north#/players/anshar/hall/room/hall11");
           return 1; 
}
realm() {return "NT"; }
