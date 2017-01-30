#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;
 

set_light(1);

short_desc = "Dept. Mech. Engr." ;
long_desc =
     "   This corridor allows you to proceed toward more interesting\n"+
     "areas such as teaching rooms, studies, offices and laboratories. \n"+
     "This is the technical zone.\n",
items = ({
   

});

dest_dir = ({
   "/players/francesco/univ/rooms/dimec2.c","south",
   "/players/francesco/univ/rooms/dimec6.c","east",
   "/players/francesco/univ/rooms/dimec9.c","north",
   "/players/francesco/univ/rooms/dimec7.c","west",  
   "/players/francesco/univ/rooms/dimec5b.c","down",
});

}
