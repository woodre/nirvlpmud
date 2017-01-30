
#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("dealer_board", this_object())){
 move_object(clone_object("/players/maledicta/closed/dealers/dealerboard.c"), this_object());
 }
  if(arg) return;
set_light(1);
short_desc = ""+HIG+"Derellia IV"+NORM+"[medical shop]";
long_desc =
"This is the back room of the Derellia Medical Shop. There is\n"+
"little here except for a chair and a computer display on the\n"+
"wall. A door leads back out to the shop.\n";

items = ({
 "chair", "A leather chair that has seen much use",
 "wall", "A blank wall with a computer display set in it",
 "door", "A wooden door that leads back out to the shop",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t10.c","out",
});

}

init(){
    ::init();
if(this_player()) 
if(!present("drug_dealer", this_player()))
 move_object(this_player(), "/players/maledicta/town/rooms/t10.c");
 	
}
