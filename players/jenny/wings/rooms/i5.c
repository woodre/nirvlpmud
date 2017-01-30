inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int justonce;
realm() { return "NT"; }
reset(arg) {
   justonce = 0;
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice the ceiling is damaged."+NORM);
     set_smell(BOLD+"This corridor has a musty smell."+NORM);
long_desc=
"This narrow, musty corridor runs from the ice surface to\n"+      
"the player's facilities.  The white tile walls look very clean.\n"+
"The grey cement floor looks clean as well, despite years of\n"+
"use.  The ceiling tiles above you are noticeably damaged.\n"+
"The door to the visitors locker room is to the south.\n";
items = ({
"ceiling","The white ceiling tiles have been noticeably damaged.  The\n"+
              "Russian players did this while warming up for a game by\n"+
               "kicking a soccer ball around",
"door","This door leads to the visitors locker room.  It is locked because\n"+
             "the visiting team does not wish to be disturbed",
"walls","The walls are made of white tile.  They look like they have been\n"+
              "washed recently.  It gives the corridor a very cold feel",
"floor","The floor is made of cement.  The grey color adds to the cold\n"+
             "feel of the corridor",
});

dest_dir = ({
"/players/jenny/wings/rooms/i4","west",
"/players/jenny/wings/rooms/parking","exit",
});
}
short() {
return BOLD+WHT+"A corridor"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("karen","listen");
}
  karen() {
    if(!present("newman") && justonce < 1) {
      MOCO("/players/jenny/wings/mobs/staff/newman.c"),TO); 
      write(BOLD+"You hear a woman walking up behind you."+NORM+"\n");
      justonce = 69;
return 1; }}
