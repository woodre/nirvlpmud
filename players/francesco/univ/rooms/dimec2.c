#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;


set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   Along the corridor you can see indications how to reach the\n"+
     "different zones of the Department of Mechanical Engineering.  \n"+
     "This is the administrative area.\n",


items = ({
     

});

dest_dir = ({
  "/players/francesco/univ/rooms/dimec5.c","north",
  "/players/francesco/univ/rooms/dimec1.c","south",
  "/players/francesco/univ/rooms/dimec3.c","east",  
  "/players/francesco/univ/rooms/dimec4.c","west",
});

}
