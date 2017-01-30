
inherit "room/room";

reset(arg) {
  if (arg) return 0;

  set_light(1);
  short_desc="The Great Hall";
  long_desc="     Passages from the east and west intersect here in what\n"+
            "appears to be some sort of meeting hall. There are two stone\n"+
            "chairs piled with cushions set in the middle of the room apon\n"+
            "a low dais. There is a passage to the north that seems to be\n"+
            "carpeted plushly.\n";
  items=({
    "passages", "To the east and west, some sort of guardposts",
    "hall",     "Some sort of meeting chamber, as of a noble to his charges",
    "chairs",   "Rugged marble of black with gold flecking",
    "cushions", "Plush and comfortable looking, necessary in the hard chairs",
    "dais",     "Three short steps lead up to a platform on which the chairs rest",
    "carpet",   "Thick carpet lines the exit to the north.",
  });
  dest_dir=({
    "/players/anshar/hall/room/hall10", "north",
    "/players/anshar/hall/room/hall7", "west",
    "/players/anshar/hall/room/hall8", "east",
  });
if(!present("tanu"))
{
move_object(clone_object("/players/anshar/hall/mon/tanu"),this_object());
}
if(!present("coran"))
{
move_object(clone_object("/players/anshar/hall/mon/coran"),this_object());
}
}
init() {
   ::init();
   add_action("north","north");

   }

  north() {
           if(present("tanu") || present("coran")) { 
           write("You cannot pass.\n"); 
           say(""+this_player()->query_name()+" is prevented from going north.\n");
           return 1; }
           this_player()->move_player("north#/players/anshar/hall/room/hall10");
           return 1; 
}

