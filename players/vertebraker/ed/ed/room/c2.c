okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "The back of the cabin";
    long_desc =
"     The backdoor of the cabin here is blocked by an explicably large amount of\n"+
"furniture piled up against the door as if to stop something from entering\n"+
"the cabin.  There is a great deal of blood and gore spattered around the sides\n"+
"of the room, as if something terrible has occured here.  A single solitary\n"+
"breeze blows in through a small shattered window, its glass barely hanging\n"+
"off of a thin frame.\n";
    dest_dir = ({
ED1ROOM+"c1","west",
ED1ROOM+"c3","east",
ED1ROOM+"c5","south",
});

items = ({
"backdoor",
"Furniture is propped against the door of the cabin to prevent exit or entrance",
"furniture","Chairs, tables, and a sofa have been jammed against the door",
"blood","Dark red human blood has stained the walls and floor here",
"gore",
"It almost appears as if someone has 'exploded' here...  You wonder again\n"+
"what has gone on...",
"window","A broken window is thinly veiled by a blind",
"blind","A crumpled Venetian blind shades the room from wandering eyes",
"glass","Sharp, jagged glass clings from a thin frame",
"frame","A thin window frame divides the window into four sections",
});
 }

init() {
    ::init();
    add_action("search","search");
 }

search(arg) {
  if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+" but turn up nothing.\n"); return 1; }
    return 1; }


realm() { return "NT"; }
