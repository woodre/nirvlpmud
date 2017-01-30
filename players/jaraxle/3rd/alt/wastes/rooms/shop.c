#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   add_property("PK");
   add_property("NT");
   short_desc = BLK+BOLD+"Wastelands "+NORM+RED+"3031 "+NORM+HIC+"["+BOLD+"shop"+HIC+"]"+NORM;
   long_desc =
   "  A small dark cave with very jagged rocks surrounding what\n"+
   "looks like a long stone desk.  Behind the desk hangs a stone\n"+
   "chiseled plaque.  Along each wall are old wooden shelves\n"+
   "with dusted items scattered about.\n";
   add_item("rocks","Sharp jagged rocks creating a dangerous cave");
   add_item("desk","A large stone desk");
   add_item("plaque","A large stone plaque with chiseled writing you cannot understand");
   add_item("shelves","Wooden shelves stacked with items");
   add_item("items","Bottles, boxes, and various other containers");
   add_item("dust","Dust covers all the items from not being used");
   add_exit("/players/jaraxle/3rd/alt/wastes/rooms/entrance.c","north");
}

