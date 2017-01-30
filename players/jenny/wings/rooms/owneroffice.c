inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("mike llitch"))  {
if(random(100) > 12) {
MOCO("/players/jenny/wings/mobs/staff/llitch.c"),TO); }}
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice some pictures on the walls."+NORM);
long_desc=
"This large office belongs to owner Mike Ilitch.  The thick light\n"+      
"brown carpeting feels very soft.  The walls are painted off-white,\n"+
"and decorated with pictures and wood trim.  A large desk is at\n"+
"the back of the room, with a chair behind it, and two chairs in\n"+
"front of it.\n";
items = ({
"desk","A large antique cherry desk with a shinny finish.  All of the drawers\n"+
             "have fancy brass handles and locks.  A telephone sits on top of\n"+
             "the desk",
"walls","The walls are painted off-white, with wood trim around the\n"+
              "edges.  They are decorated with plenty of pictures",
"pictures","There are pictures of the Ilitch family, the 1997 and 1998\n"+
                 "championship teams, and a picture of Mr. Ilitch with\n"+
                 "Vladimir Konstantinov",
"trim","Dark stained wooden trim that is along the edges of the walls",
"chairs","A very comfortable black leather chair is behind the desk, and two\n"+
             "slightly less expensive leather chairs are in front of it",
"carpeting","The carpeting is thick, light brown, and well padded.  Just like\n"+
                    "you would have in a living room",
"phone","A plain black telephone with buttons on it to support multiple lines",	
});

dest_dir = ({
"/players/jenny/wings/rooms/s2","leave",
});
}
short() {
return BOLD+RED+"Owner's Office"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
