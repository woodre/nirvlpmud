#include "/players/jaraxle/define.h"
#include "/players/jaraxle/3rd/alt/mobs/random.h"
inherit "/players/jaraxle/3rd/alt/rooms/room2.c";

reset(arg) {
   if(arg) return;
   set_light(0);
   short_desc = BLK+BOLD+"The Magic Shop"+NORM;
   long_desc =
   "  A small, heavenly meadow on the side of the\n"+
   "northroad.  For some reason this meadow has\n"+
   "not aged nor deteriorated at all like the\n"+
   "rest of the realms.\n";
   add_item("grass","Nasty crab grass; rotten, and dying.");
   add_item("sign","\t\t"+HIC+"-= "+HIW+"For Sale"+HIC+" =-\n\n"+
      HIW+"\t."+HIC+"["+BLK+" Earth Orb      : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Flame Orb      : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Good Orb       : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Hate Orb       : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Laser Orb      : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Love Orb       : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Lightning Orb  : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Poison Orb     : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Water Orb      : 4000 coins "+HIC+"]"+HIW+".\n"+
      HIW+"\t."+HIC+"["+BLK+" Wind Orb       : 4000 coins "+HIC+"]"+HIW+"."+NORM+"\n"+
      HIW+"\t."+HIC+"["+BLK+" Empty Bottle   : 4000 coins "+HIC+"]"+HIW+"."+NORM+"\n"+
      "\n\t."+HIC+"-= "+BLK+BOLD+"Buy "+HIC+"< "+BLK+BOLD+"type"+HIC+" >"+BLK+BOLD+" for purchase "+HIC+"=-"+NORM);
   add_object("/players/jaraxle/3rd/alt/mobs/magi.c");
   add_exit("/players/jaraxle/3rd/alt/rooms/northroad2.c","east");
   
}

init() {
   ::init();
   add_action("buy_it","buy");
   
}

buy_it(arg){
   if(!arg){ write("Buy what?\n"); return 1; }
   write("Alejandro is not here to sell anything.\n");
   return 1; }
