okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "A sitting room";
    long_desc =
"     A creaky rocking chair leans against the southwest wall as you gaze\n"+
"around the room.  A pastel painting is hanging from the wall, next to a\n"+
"small marble bust.  The two large glass windows provide portals of viewing\n"+
"to the dangerous forest looming outside.  A set of two wooden chairs stand\n"+
"next to a short coffee table.  The bedroom lies to the south, and west\n"+
"leads to the backdoor of the cabin.\n";
    if(!present("linda",TO)) MOCO(ED1MOB+"linda"),TO);
dest_dir = ({
ED1ROOM+"c6","south",
ED1ROOM+"c2","west",
  });
items = ({
"chair","A thin, old wooden rocking chair creaks back and forth..",
"painting","The oil pastels swirl around, creating a life of its own inside the frame",
"bust","A small replica marble bust lies here, detailing the head of Alexander the Great",
"windows","Two large glass windows provide a glance outside to the dark forests",
"forest","All you can see is the mysterious woods outside",
"chairs","Two small oaken chairs are seated next to a small table",
"table","The small coffee table barely reaches two feet off the ground.\nA magazine lies on top",
"magazine","An issue of FANGORIA horror-fan magazine",
});
    }

init() {
    ::init();
    add_action("search","search"); }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but find nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }

set_slime() {
    int x;
    x = random(4);
    if(x == 0) long_desc = long_desc+RED+"Massive amounts of blood stains the walls and floor.\n"+NORM;
    if(x == 1) long_desc = long_desc+GRN+"Green slime and gore ooze from the remaining body parts spread here.\n"+NORM;
    if(x == 2) long_desc = long_desc+"The floor boards here have an odd tint to them.\n";
    if(x == 3) long_desc = long_desc+"A faint mist pours up from beneath the thin floorboards.\n";
    return 1; }
