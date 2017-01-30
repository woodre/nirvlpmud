#include "/players/snakespear/closed/ansi.h"
inherit "room/room";

reset(arg) {
   if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/bgar.c"),this_object());
   }
   if(!present("sign")) {
     move_object(clone_object("/players/snakespear/zultayne/warning.c"),this_object()); 
   }
   if(!present("messenger")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/msgent.c"),this_object()); 
   }
   if(arg) return;   
set_light(3);
short_desc=("Outside "+GRY+"Zultayne"+NORM);
long_desc=
 "  This is the front of Zultayne, the Gargoyle Stronghold.  Tall pines line\n"+
 "the path leading to the large doors.  The walls to the stronghold are very\n"+
 "tall and look very old.  The air is very thick here, yet has a sweet aroma.\n"+
 "This is where the final battle for the stronghold took place.  One might\n"+
 "give a second thought to entering the stronghold.\n";
       
items=({
     "pines", "Large trees, full of pine needles",
     "path", "A small path that leads up to the large doors",
     "doors", "Large wooden doors adorned with dull brass knockers",
     "walls", "The outer barrier of the stronghold.",
     "trees","Large pine trees that look healthy",
     "knockers","Large brass objects for knocking on the doors",
     "stronghold","A large, run down castle",
});
      
dest_dir=({
     "/room/south/sforst1","leave",
     "/players/snakespear/zultayne/rooms/foyer.c","intrude",
});
}

realm() { return "NT"; }

init() {
   ::init();
   add_action("search_room","search");
   add_action("afraid","scared");
   add_action("listen","listen");
   add_action("smell","smell");
   add_action("iintrude","intrude");
}
search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "path") {
	    write("You find alot of footprints, going in the opposite direction.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "air") {
	    write("Thick, musky air that carries death in it's wings.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "trees") {
	    write("Soft moans as the wind whistles through the branches.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
afraid() {
   call_other(this_player(),"move_player","in fright#room/church.c");
   return 1;
}
iintrude() {
   if(this_player()->query_level() >14) {
   call_other(this_player(),"move_player","fate#players/snakespear/zultayne/rooms/bchoice.c");
   return 1; }
}

