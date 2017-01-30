#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
 

set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   This room has other posters on its walls, that still show\n"+
     "departmental research activities.  Most of them are copies of\n"+
     "papers published in Journals, Magazines and Periodicals.\n",
items = ({
    "posters","They summarize the contents of the papers",   
    "walls","Freshly white painted, they hold some posters on",
});

dest_dir = ({
   "/players/francesco/univ/rooms/dimec12.c","south",
   "/players/francesco/univ/rooms/dimec16.c","west",
   "/players/francesco/univ/rooms/dimec18.c","north",
   "/players/francesco/univ/rooms/dimec17.c","east",
});

}
