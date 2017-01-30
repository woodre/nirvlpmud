
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
dest_dir = ({
"/players/rich/bridge.c","out",
});

}
long(){
write("A large open plain.\n"+
      "There are three obvious exits: north, east and south\n");
if(this_player())
if(present("clan_symbio", this_player())){
write("The true exit is 'out'.\n"+
	  "There is a "+HIG+"Display"+NORM+" here.\n");
return 1;
}
return 1;
}

short(){ 
	string desc;
	switch(random(4) + 1){
           case 4: desc = "The Forest <Forbidden>  [e,w]";   break;
           case 3: desc = "The Forest <Forbidden>  [n,e,s,w]"; break;
           case 2: desc = "Before the Castle of the Forbidden  [e,back]"; break;
           case 1: desc = "The Forest <Forbidden>  [e,s]";   break;
	}
	return desc; 
}

init(){
    ::init();
if(this_player()) 
if(!present("clan_symbio", this_player()) && !this_player()->is_pet())
 move_object(this_player(), "/players/maledicta/ruins/rooms/r7.c");
add_action("change_short", "short");
}

