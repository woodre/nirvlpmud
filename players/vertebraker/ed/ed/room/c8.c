okay_follow() { return 1; }

#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "A foyer";
   long_desc =
   "     You stand in the foyer of a very old, yet well-built wood log cabin.\n"+
   "Beams fasten and steady the walls, heavy as they are.  There is a large\n"+
   "door leading to the outside of the cabin, and a few small glass-guarded\n"+
   "windows.  The boards creak under your feet as you step, and you hear \n"+
   "strange noises all around you!\n";
   items = ({
         "beams","Large wooden beams are holding up the massive walls of the cabin",
         "door","There is a large doorway leading outside from the cabin.  The door is open",
         "windows","Peering outside the windows, you spy a small shack and the darkness of the forest",
         "boards","The floor creaks with every step you take, as if it will give out any time soon",
         "shack","A small tool shack is visible just outside the house",
         "walls","The cabin's mighty walls are decorated with hunting trophies",
         "trophies","Deer, elk, and moose-head alike decorate the walls",
         "darkness","You wonder what could be lurking out there, beyond the walls of the cabin!",
});
   dest_dir = ({
         ED1ROOM+"o1","out",
         ED1ROOM+"c5","north",
         ED1ROOM+"c7","west",
         ED1ROOM+"c9","east",
});
}

init() {
   ::init();
   add_action("search","search");
}

search(arg) {
   if(!arg) { write("Your general search turns up nothing.\n"); return 1; }
   if(arg) { write("Your search of "+arg+" turns up nothing.\n"); return 1; }
}

realm() { return "NT"; }
