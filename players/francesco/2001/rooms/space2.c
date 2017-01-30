#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Space Shuttle 5" ;
long_desc =
     "   SPACE SHUTTLE 5,  YEAR 2001\n"+
     "The communication area of the Space Shuttle 5 is a well ordered room.\n"+
     "The light is relaxing, it doesnt hurt the eyes of the freshly arrived\n"+
     "travellers.  On a side desk there is a screen where the image of the\n"+
     "other far talker can be displayed.  A small microphone allows for\n"+
     "communicating.\n",

items = ({
   "desk","It is a metallic front desk about 3 feet tall and 5 feet wide",
   "screen", "It is a color LCD monitor",
   "microphone","This metallic pole looks useful to communicate remotely",
});

dest_dir = ({
  "/players/francesco/2001/rooms/space5.c","north",
  "/players/francesco/2001/rooms/space1.c","east",
});

}
