inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("nill"))  {
if(random(100) < 25) {
MOCO("/players/jenny/wings/mobs/staff/nill.c"),TO); }}
if(!present("ken holland"))  {
if(random(100) > 7) {
MOCO("/players/jenny/wings/mobs/staff/holland.c"),TO); }}
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some pictures on the walls."+NORM);
long_desc=
"This office belongs to general manager Ken Holland.  It has thick\n"+      
"red carpet and off-white walls that are decorated with plenty of\n"+
"pictures.  There is a large desk towards the back of the room, with\n"+
"a chair behind it, and two chairs in front of it.  One corner of the\n"+
"office has small table with a computer on it, a metal file cabinet is\n"+
"in the other.\n";
items = ({
"desk","This is a beautiful oak desk.  All of the drawers have fancy brass\n"+
             "handles.  A telephone sits on top of the desk",
"walls","The walls are painted off-white and decorated with plenty\n"+
              "of pictures",
"pictures","The walls are decorated with lots of pictures of great Red Wings\n"+
                 "from the past",
"table","A small wooden table with a computer sitting on it",
"chairs","A very comfortable leather chair is behind the desk, and two\n"+
             "slightly less expensive leather chairs in front of it",
"carpet","The carpeting is thick, red, and well padded.  Just like\n"+
                    "you would have in a living room",
"telephone","A plain black telephone with buttons on it to support multiple lines",	
"chair","A very comfortable leather chair is behind the desk, and two\n"+
"slightly less expensive leather chairs in front of it",
"computer","A desktop computer, monitor, and printer",
"cabinet","A light brown metal filing cabinet.  Copies of contracts, as well as\n"+
                "scouting reports are in there",
});

dest_dir = ({
"/players/jenny/wings/rooms/s2","leave",
});
}
short() {
return BOLD+RED+"General Manager's Office"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
