#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;


set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   The corridor is mainly surrounded by laboratories where the\n"+
     "experimental activities of the department are carried out.  This\n"+
     "is still the technical area.\n",


items = ({
   

});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec12.c","north",
  "/players/francesco/univ/rooms/dimec5.c","south",
  "/players/francesco/univ/rooms/dimec10.c","east",  
  "/players/francesco/univ/rooms/dimec8.c","west",
});

}
