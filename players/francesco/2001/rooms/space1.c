#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
if (!present("narrator")) {
  move_object(clone_object("/players/francesco/2001/mobs/narrator2.c"),
	this_object());  }
set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "The reception area of the Space Shuttle 5 is a well ordered room.\n"+
     "The light is relaxing, it doesnt hurt the eyes of the freshly arrived\n"+
     "travellers.  On a side desk there is a computer screen with an image\n"+
     "of a receptionist on it.  A small microphone allows for communicating\n"+
     "with her.  A flashing scanner laying on the same desk has an imprinting\n"+
     "of a hand on it.\n",

items = ({
   "desk","It is a metallic front desk about 3 feet tall and 5 feet wide",
   "screen", "It is a color LCD monitor",
   "microphone","This metallic pole looks useful to communicate remotely",
   "scanner","It is a flat bed scanner, and it is used to recognize the\n"+
             "guests from their hand print",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space4.c","north",
  "/players/francesco/2001/rooms/space2.c","west",
});

}

query_no_fight() {return 1;}
