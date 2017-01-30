inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_smell(""+YEL+"This room smells like feet."+NORM+"\n");
set_search(""+BOLD+"You find the hamper and notice Al's clothes for the next day."+NORM+"\n");
short_desc=(""+CYN+"Al and Peg Bundy's room."+NORM+"");
long_desc=
"This room belongs to Al and Peg Bundy.  Not a lot of sex goes\n"+
"on in this room, and you better believe Peg isn't happy about\n"+
"that.  This room is somewhat plain.  There is a bed in the center,\n"+
"and a window along the wall.\n";
items = ({
"bed","This is the bed that Al sometimes uses to give Peg the best 30 seconds of her life",
"window","Aliens once came in through this window and stole Al's socks",
"wall","A plain looking wall.  It hasn't been washed in a while",
"hamper","This is full of dirty clothes.  They will never be washed",
});

dest_dir = ({
 "/players/jenny/bundy/rooms/u3b","west",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
