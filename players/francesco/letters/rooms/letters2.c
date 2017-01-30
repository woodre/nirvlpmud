#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Letters Department" ;
long_desc =
     "   The main corridor in the Letters Department is filled with\n"+
     "shelves on the sides.  It is well lit by lights hanging on the\n"+
     "ceiling.  On the walls there are some posters and announcements.\n"+
     "Through two open passageways it is possible to view two stands.\n",

items = ({
   "corridor","It is approximately fifty feet long and ten feet wide",
   "ceiling","Of a semi-circular shape, like the old roman arches",
   "lights","They are flickering neon lights",
   "walls","White painted, perfectly maintained",   
   "posters","Some of them show the contents of papers presented\n"+
             "in early Conferences.  Others show some research\n"+
             "themes performed in the Letters Department", 
   "announcements","They announce incoming Conferences",
   "shelves","They are closed with a glass window, and carry bazillions of books",
   "passageways","They lead respectively east and west",
   "stands","The stands are metallic and each of them hold a sign",
   "sign","They supposedly have something written on, but is it not\n"+
          "possible to read it from this afar",
});

dest_dir = ({
  "/players/francesco/letters/rooms/letters5.c","north",
  "/players/francesco/letters/rooms/letters1.c","south",
  "/players/francesco/letters/rooms/letters3.c","west",
  "/players/francesco/letters/rooms/letters4.c","east"
});

}

init() {
    ::init();
}

