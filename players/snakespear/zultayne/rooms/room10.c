#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg){
   if(!present("gargoyle")) {
      move_object(clone_object("/players/snakespear/zultayne/critters/hemgar.c"),this_object()); }
   if(!arg){
set_light(1);
short_desc="Top of East Tower";
long_desc=
 "  This must be the top of the east tower.  There are no windows here, but\n"+
 "the temperature has dropped some because of the altitude.  The walls here\n"+
 "are a silvery black.  Hematite covers the floor and ceiling, making them\n"+
 "shine with any small light that hits their surface.\n";

items=({
     "walls","Silvery black hematite walls that shine",
     "hematite","Strong rock with a smooth surface",
     "light","Small beams of light that come from the entrance",
     "surface","A smooth and shiney rock known as hematite",
     "floor","It looks like a sheet of black ice",
     "ceiling","A large rounded dome made of hematite",
     "rock","Dark, silvery looking hematite",
     "dome","The ceiling is shaped like a dome",
});

dest_dir=({
     "/players/snakespear/zultayne/rooms/room9.c","down",
     "/players/snakespear/zultayne/rooms/foyer.c","jump",
});

}   }

realm() { return "NT"; }

init() {
   ::init();
   add_action("smell","smell");
   add_action("listen","listen");
   add_action("search_room","search");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "floor") {
	    write("You shuffle around the floor and find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "hematite") {
	    write("You're unable to smell anything special.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "walls") {
	    write("A voice tells you: Findddd the plaqqquue...\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}

