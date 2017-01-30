#include <ansi.h>

inherit "room/room";
  reset(arg) {
    if(!present("gargoyle")) {
     move_object(clone_object("/players/snakespear/zultayne/critters/amazgar.c"),this_object());
   }   
if(arg) return;
set_light(0);
short_desc=HIR+"Feast Hall"+NORM;
long_desc=
 "  The large hall is decorated rather lavishly.  A large table sits in\n"+
 "the middle of the room.  There are a dozen chairs that align around\n"+
 "the table.  On the table there lays a large stained cloth.  Each chair\n"+
 "has a setting already placed.  Several candle holders line up through\n"+
 "the center of the table.\n";

items=({
     "table","A large stone table that looks very heavy and stable",
     "chairs","Large stone chairs with very high backs on them",
     "cloth","A delicately embroidered tablecloth, stained with wine",
     "setting","Fine steel silverware and heavy looking metal goblets and plates",
     "holders","Large iron candle holders that are covered in dried wax",
     "silverware","Eating utencils forged from great siver",
     "goblets","Delicate drinking containers",
     "plates","Steel plates that have been dented",
     "wax","Old, dust covered wax that has been here awhile",
     "containers","Heavy metal goblets used for drinking",
     "utencils","A variety of used items for eating",
});

dest_dir=({
    "/players/snakespear/zultayne/rooms/room2.c","east",
});
}

realm() { return "NT"; }

init() {
  ::init();
  add_action("search_room","search");
  add_action("listen","listen");
  add_action("smell","smell");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
   if(str == "containers") {
	    write("You search them all and find nothing.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "goblets") {
	    write("You smell old ales.  It's disgusting!\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "room") {
	    write("You can hear nothing.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}

