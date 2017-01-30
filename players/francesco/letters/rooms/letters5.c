#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Letters Department" ;
long_desc =
     "    The main corridor in the Letters Department is filled with\n"+
     "shelves on the sides.  It is well lit by lights hanging on the\n"+
     "ceiling.  On the walls there are some posters and announcements.\n"+
     "On the west door there is a small tag.  An open passageway leads\n"+
     "east.  There is a noun written above it.\n"+
     "\n",

items = ({
   "corridor","It is approximately fifty feet long and ten feet wide",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "lights","They are flickering neon lights",
   "walls","White painted, perfectly maintained",   
   "posters","Some of them show the contents of papers presented\n"+
             "in early Conferences.  Others show some research themes\n"+
             "carried on in the Letters Department", 
   "announcements","They announce incoming Conferences",
   "shelves","They are closed with a glass window, and carry bazillions of books",
   "passageway","Through it, it is possible to see some tables and more shelves",   
   "tables","They are of rectangular shape, with several chairs around",
   "chairs","Plain upholstered seats, they look comfortable",
   "noun","LIBRARY",
});

dest_dir = ({
/*  "/players/francesco/letters/rooms/letters8.c","north",*/
  "/players/francesco/letters/rooms/letters2.c","south",
  "/players/francesco/letters/rooms/letters6.c","west",
  "/players/francesco/letters/rooms/letters7.c","east"
});

}

init() {
    ::init();
}

