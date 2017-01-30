okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
    if(arg) return;
    short_desc = "Guest bedroom";
    long_desc =
"     You stand in the guest bedroom.  There is a queen-sized bed in the\n"+
"middle of the room and a small nightstand on the right side of it, with a\n"+
"lamp on it.  The room is softly lit, and a throw rug is on the floor.\n"+
"Clothes are scattered around the room, and there is a fairly large wardrobe\n"+
"on the other side of this room.  A small window provides a view outside\n"+
"of the cabin.\n";
    dest_dir = ({
ED1ROOM+"c3","north",
ED1ROOM+"c9","south",
ED1ROOM+"c5","west",
});
    set_light(1);
    items = ({
"bed","A large, fluffy bed lies in the middle of this quaint room",
"nightstand","A small nightstand stands here, covered by a small dustcloth, just below a lamp",
"lamp","A small lamp sits atop the nightstand",
"rug","A plush, intricately-designed rug has been laid on the ground in front of the bed",
"clothes","Jeans, shirts, and socks are scattered around the room in haphazard fashion",
"wardrobe","A large wooden wardrobe looms in the corner",
"window","A cracked glass window reflects moonbeams into the room",
});
}

init() {
    ::init();
    add_action("search","search"); }

search(arg) {
    if(!arg) { write("Your general search of the area turns up nothing.\n"); return 1; }
    if(arg) { write("You search "+arg+", but you turn up nothing.\n"); return 1; }
    return 1; }

realm() { return "NT"; }
