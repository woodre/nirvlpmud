#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
  if(arg) return;

set_light(1);

short_desc = "Computer laboratory" ;
long_desc =
     "   Several booths in this room allow students to work and to code\n"+
     "without being annoyed nor disturbed.  Each booth is equipped with\n"+
     "a computer which is supposedly linked to the others via a local\n"+
     "network.  The central booth looks somewhat different.\n",
items = ({
	"booth","The centered booth in this room is likely the office of the\n"+
		"system manager which doesnt want to be disturbed nor bothered\n"+
		"at all.  If you enter,  then you might get a harsh welcome",  
        "booths","About 20 boxes of rectangular shape, secluded to each other",


});

dest_dir = ({
    "/players/francesco/univ/rooms/dimec9.c","west",
    "/players/francesco/univ/rooms/dimec11.c","enter",
});

}
