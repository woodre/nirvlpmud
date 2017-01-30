#include "/players/daranath/guild/defs.h"
#define TP this_player()

inherit "room/room";

reset(arg) {
if(arg) return;

  set_light(1);
  short_desc= "Century 21 - Qual'tor Office";
  long_desc= 
    "The small gold colored building opens into a plush office\n"+
    "very out of place for the majority of Qual'tor. The office\n"+
    "itself has several desks and other office type furniture\n"+
    "about the area. A small doorway leads west with a small sign\n"+
    "that reads: Employees Only.\n"+
    "Commands here are info, info_list and bid.\n";

  dest_dir=({
   "/players/daranath/qualtor/mansion/cen21b.c","west",
   "/players/daranath/qualtor/merch_way.c","south",
  });
}

init() {
  ::init();
   add_action("inform","info");
   add_action("info_list","info_list");
   add_action("mansbid","bid");
   add_action("dar_west","west");
}

inform(str) {
  if(!str) {write("What would you like information on?\n"+
     "info_list for a list of options.\n"); return 1; }
if(str == "costlist") {cat("/players/daranath/qualtor/mansion/docs/costlist.txt"); return 1; }
if(str == "recall") {cat("/players/daranath/qualtor/mansion/docs/recall.txt"); return 1;}
if(str == "login") {cat("/players/daranath/qualtor/mansion/docs/login.txt"); return 1;}
if(str == "heal") {cat("/players/daranath/qualtor/mansion/docs/heal.txt"); return 1; }
if(str == "invite") {cat("/players/daranath/qualtor/mansion/docs/invite.txt"); return 1; }
if(str == "guard") {cat("/players/daranath/qualtor/mansion/docs/guard.txt"); return 1; }
if(str == "trophy") {cat("/players/daranath/qualtor/mansion/docs/trophy.txt"); return 1;}
if(str == "shop") {cat("/players/daranath/qualtor/mansion/docs/shop.txt"); return 1;}
if(str == "portal") {cat("/players/daranath/qualtor/mansion/docs/portal.txt"); return 1;}
if(str == "item") {cat("/players/daranath/qualtor/mansion/docs/item.txt"); return 1;}
if(str == "bidding") {cat("/players/daranath/qualtor/mansion/docs/bidding.txt"); return 1;}
else { write("What would you like information on?\n"+
       "info_list for a list of options.\n");
return 1; }
}

info_list() {
write("\nA listing of items you can get help on here:\n\n"+
      "costlist, login, recall, guard, invite, item\n"+
      "heal, shop, trophy, portal\n\n"+
      "NEW ---> bidding\n");
return 1; 
}

mansbid(){
write("The bidding for the mansions take place starting sept 18th.\n");
return 1;
}

dar_west(){
write("\nHey!!!  The sign says employees only!!!\n\n");
return 1; 
}

