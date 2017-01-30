#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Melody");
   set_alias("jeweller");
   set_alt_name("melody");
   set_race("human");
   set_gender("female");
   set_short("Melody");
   set_long(
      "A short, full figured woman with long locks of bright red hair tied up"+
      "in pigtails.  Melody\n"+
      "has a small magnifying lense over one eye.  Her clothing is laced with"+
      "all types of jewels\n"+
      "from across the realms.\n");
   
   set_level(16);
   set_hp(600);
   set_al(0);
   set_wc(15);
   set_ac(15);
   set_aggressive(0);
   
   set_chat_chance(8);
   load_chat("Melody eyes a gem carefully.\n");
   
}

init() {
   
   ::init();
   
   add_action("buy_it","buy");
}
buy_it(arg) {
   if(TP->query_money() < 2100){
      write("Melody refused to sell you something when you do not have the"+
         "money to pay for it.\n");
      return 1; }
   if(!TP->add_weight(1)){ write("Melody tells you: You cant carry this!\n");
      return 1; }
   if(arg == "diamond") {
      TP->add_money(-2100);
      write("Melody places a "+HIW+"sparkling diamond"+NORM+" in your"+
         "hands.\n");
      MOCO("/players/jaraxle/3rd/volcano/items/diamond.c"),TP);
      say(TPN+" purchases a gem from Melody.\n");
      return 1; }
if(arg == "stone"){
    TP->add_money(-2100);
   write("Melody places a repair stone in your hands.\n");
MOCO("/players/jaraxle/repair.c"),TP);
return 1; }
   if(arg == "ruby"){
      TP->add_money(-2100);
     MOCO("/players/jaraxle/3rd/volcano/items/ruby.c"),TP);
      write("Melody places a beautiful "+HIR+"red ruby"+NORM+" into your empty"+
"hands.\n");
      say(TPN+" purchases a gem from Melody.\n");
      return 1; }
   notify_fail("Melody says, 'I only sell "+HIW+"diamonds"+NORM+" and"+
HIR+"rubies"+NORM+" here.\n");
}
