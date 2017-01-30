okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc = "The master bedroom";
    long_desc =
"     The soft glow from the lamps in this room emanates an aura\n"+
"of yellow- which also matches the color of the walls.  A large glass\n"+
"patio door is all that separates this room from the terrors outside of the\n"+
"cabin.  A large bed stands in the middle of a room.  A bookcase lies in a\n"+
"corner of the room, a few pictures hang on the wall at the other corner.\n";
    items = ({
"glow","A yellowish hue emanates from the two small lamps in the room",
"walls","The yellow walls stand in stark contrast to the gloom in the rest of the house",
"door","The thick glass patio door is locked",
"bed","The king-sized bed has been neatly made by the occupants",
"bookcase","A tall bookcase looms in one corner, housing many books",
"books","Books like 'The Undead and You' and 'Secrets of the Sumerians' are piled onto the bookcase",
"pictures","The pictures detail ancient Sumerian battles and the triumphs of King Nebuchednezzar",
});
    dest_dir = ({
ED1ROOM+"c2","east",
ED1ROOM+"c4","south",
});
    }

init() {
    ::init();
    add_action("search","search"); }

realm() { return "NT"; }

search(arg) {
    if(arg) write("You search "+arg+" but find nothing.\n");
    if(!arg) write("You search the general area, but find nothing.\n");
    return 1; }
