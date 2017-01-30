inherit "/players/jenny/room";
#include "/players/jenny/define.h"
object key;
int onlyone;
realm() { return "NT"; }
reset(arg) {
   onlyone = 0;
if(!present("brent gilchrist"))  {
if(random(10) > 6) {
MOCO("/players/jenny/wings/mobs/players/gilchrist.c"),TO); }}
if(!present("john wharton"))  {
MOCO("/players/jenny/wings/mobs/staff/wharton.c"),this_object()); }
    if(arg) return;
    set_light(1);
long_desc=
"This is a small room with plain white walls and red thin red carpet.\n"+      
"A padded table sits in the middle the room, and three chairs are up\n"+
"against the wall.  A large metal cabinet is along the back wall, next\n"+
"to a closet door.  A large scale is in the corner of the room.\n";
items = ({
"table","This is a padded table.  It is about four feet long, and looks like\n"+
            "one you would find in a doctors office.  It is used for treating\n"+
             "players injuries, as well as for massages",
"chairs","These are three well padded chairs.  They look like they are made\n"+
              "out of wood and vinyl",
"carpet","This is just cheap thin red carpeting.  It keeps the blood stains from showing",
"walls","Plain white walls with no decorations whatsoever",
"scale","This is a large black scale.  It is a medical scale that works by\n"+
                       "balancing weights",
"door","A wooden door with a metal handle on it.  It seems to be locked",
"closet door","A wooden door with a metal handle on it.  It seems to be locked",
"cabinet","A large brown metal cabinet with 2 doors, 2 handles, and a keyhole\n"+
               "It could be opened",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker3","out",
});
}
short() {
return BOLD+RED+"Trainers Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("getheal","open");
}
getheal(str) {
if(str == "cabinet" || str == "the cabinet") {
key = present("jennyshotkey",TP);
if(!key) { write("You need the key.\n"); return 1;}
if(present("John Wharton")) {write("John Wharton says:  You're not allowed in there.\n"); return 1;}
if(onlyone > 0) {write("You open up the cabinet, but find nothing of interest.\n"); return 1;}
if(!TP->add_weight(1)) {write("You find a syringe, but are already carrying too much, so you leave it there.\n"); return 1;}
write("You open the cabinet and find a syringe.\n");
MOCO("/players/jenny/wings/items/shot.c"),TP);
TP->add_weight(1);
onlyone = 5;
return 1;}}
