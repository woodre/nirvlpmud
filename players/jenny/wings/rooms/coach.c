inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("scotty bowman"))  {
if(random(100) > 8) {
MOCO("/players/jenny/wings/mobs/staff/bowman.c"),TO); }}
    if(arg) return;
    set_light(1);
long_desc=
"The coaches office is large and very tidy.  The red carpeting gives\n"+      
"it a comfortable feel.  A large desk sits towards the back of the office,\n"+
"with leather chair behind it.  Two additional chairs are in front of the\n"+
"desk, and there is a couch over to the side.  The other side of the room\n"+
"has a long table with a television set sitting on top of it, and a file\n"+
"cabinet in the corner.\n";
items = ({
"carpeting","The carpeting is thick and dark red",
"desk","This is a large wooden desk made of cherry.  It has several drawers.\n"+
             "A laptop computer and a telephone are sitting on top of the desk",
"computer","This is a small, grey laptop computer.  Coach Bowman uses it\n"+
                   "to keep track of statistics, as well as gather information from\n"+
                    "the internet",
"telephone","A plain black telephone",
"couch","This is a comfortable black leather couch",
"chair","A comfortable looking black leather chair",
"chairs","Two fairly comfortable cushioned chairs positioned in front of the\n"+
               "coaches desk",
"television","A 29 inch television set, which coach Bowman likes to use to\n"+
                    "watch out of town games",
"table","A long wooden table with a television and VCR sitting on top of it",
"vcr","A VCR, which coach Bowman likes to use when reviewing game tapes",
"file cabinet","A large grey file cabinet sits in the corner of the room",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker4","out",
});
}
short() {
return BOLD+RED+"Coaches Office"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
