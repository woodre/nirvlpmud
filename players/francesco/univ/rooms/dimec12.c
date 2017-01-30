#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   You have entered the offices area.  On the walls of this corridor\n"+
     "you can see some posters depicting the departmental activities.\n"+
     "By looking deeper at them it is possible to see where those posters\n"+
     "have been presented:  World Conferences, International Meetings \n"+
     "and also some local Workshops.\n",


items = ({
      "posters","They report in short the main scientific results obtained by\n"+
                "the departmental staff and presented in Conferences",
      "walls","They have some posters attached on",
      
});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec15.c","north",
  "/players/francesco/univ/rooms/dimec9.c","south",
  "/players/francesco/univ/rooms/dimec14.c","east",  
  "/players/francesco/univ/rooms/dimec13.c","west",
});

}
