#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(!present("guard", this_object())){
      move_object(clone_object("players/jaraxle/templar/mobs/high_templar"),this_object());
   }
   if(arg) return;
   set_light(1);
   short_desc = HIW+"Templar Lockers ["+NORM+GRN+"Fortress Stone"+HIW+"]"+NORM+"";
   long_desc =
 "  The storage room walls are lined with rows upon rows of lockers. A\n"+
  "few chairs have been placed within the room, and a large"+GRN+" sign"+NORM+" hangs\n"+
  "near the doorway. A window lets light in from outside, with a view\n"+
  "of the forest beyond visible.\n";
   items = ({
"lockers","Large, spacious private lockers line the walls",
"numbers","Numbers which coreespond to the locker placement",
"bench","A long bench to rest on",
"sign","......................................................................\n"+
".                                                                    .\n"+
".  "+HIW+"buy locker"+NORM+"     Purchase a new locker, max 10  .\n"+
".                                                                    .\n"+
".  "+HIW+"withdraw "+HIG+"<"+HIW+"#"+HIG+">"+NORM+"     Withdraw <item> by #       .\n"+
".                                                                    .\n"+
".  "+HIW+"deposit "+HIG+"<"+HIW+"item"+HIG+">"+NORM+"    Deposit <item> into locker  .\n"+
".                                                                    .\n"+
".  "+HIW+"clear "+HIG+"<"+HIW+"item"+HIG+">"+NORM+"       Clears out locker space       .\n"+
".                                                                    .\n"+
".  "+HIW+"list"+NORM+"                      Lists items in your locker     .\n"+
".                                                                    .\n"+
"......................................................................\n",
});
   
   dest_dir = ({
"/players/jaraxle/templar/rooms/equipment.c","west",
});
   
}

init(){
   ::init();
   add_action("withdraw","withdraw");
   add_action("list", "list");
   add_action("deposit","deposit");
   add_action("buylocker","buy");
   add_action("clear","clear");
}

deposit(str){
   "/players/catwoman/tl.c"->deposit_item(str);
   return 1;
}
buylocker(str){
   "/players/catwoman/tl.c"->buy_locker(str);
   return 1;
}
list(){
   "/players/catwoman/tl.c"->list();
   return 1;
}
withdraw(str){
   "/players/catwoman/tl.c"->withdraw_item(str);
   return 1;
}
clear(str){
   "/players/catwoman/tl.c"->clear(str);
   return 1;
}
