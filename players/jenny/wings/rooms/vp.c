inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("jimmy devellano"))  {
MOCO("/players/jenny/wings/mobs/staff/jimmyd.c"),TO); }
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some pictures on the wall."+NORM);
long_desc=
"This office belongs to Jimmy Devellano, the team's Senior Vice\n"+      
"President.  The thick blue carpeting brightens up the room.  The\n"+
"walls are off-white, and decorated with lots of pictures.  There\n"+
"are several chairs in the room, and a large desk towards the back.\n"+
"A metal filing cabinet is in the corner.\n";
items = ({
"desk","This is a beautiful cherry desk.  All of the drawers have fancy brass\n"+
             "handles.  A telephone sits on top of the desk",
"walls","The walls are painted off-white and decorated with plenty\n"+
              "of pictures",
"pictures","The walls are decorated with lots of pictures of players\n"+
                 "Devellano has drafted",
"chairs","There are several comfortable padded chairs throughout the\n"+
             "office, and a leather chair behind the desk",
"carpet","The carpeting is thick, blue, and well padded",
"telephone","A plain black telephone with buttons on it to support multiple lines",     
"cabinet","A light brown metal filing cabinet",
});

dest_dir = ({
"/players/jenny/wings/rooms/s3","leave",
});
}
short() {
return BOLD+RED+"Office of the Senior V.P."+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
