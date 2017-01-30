
#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("dealer_board", this_object())){
 move_object(clone_object("/players/maledicta/closed/symbio/symbioboard.c"), this_object());
 }
  if(arg) return;
set_light(1);
short_desc = "Dark room";
long_desc =
"This is the back room of the armor shop.  There is\n"+
"a door that leads back out to the shop.\n";

items = ({
 "door", "A wooden door that leads back out to the shop",
});

dest_dir = ({
  "/players/maledicta/town/rooms/t18.c","out",
});

}

short(){ return "Dark room"; }

init(){
    ::init();
if(this_player()) 
if(!present("clan_symbio", this_player()) && !this_player()->is_pet())
 move_object(this_player(), "/players/maledicta/town/rooms/t18.c");
 	
}
