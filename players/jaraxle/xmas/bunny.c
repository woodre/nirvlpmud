#include "/players/jaraxle/define.h"
inherit "obj/monster.c";

reset(arg)  {
   object gold;
   ::reset(arg);
   if(arg) return;
   
   set_name("Easter Bunny");
   set_alias("bunny");
   set_alt_name("easter bunny");
   set_race("rabbit");
   set_short("Easter Bunny");
   set_long(
      "LOOK!!  It's the EASTER BUNNY!  He has a basket full of eggs in his hands too!\nMaybe you can "+HIW+"<"+HIC+"ask bunny"+HIW+">"+NORM+" to see if he will give you one.\n");
   set_level(100);
   set_hp(300000000);
   set_al(1500);
   set_wc(0);
   set_ac(100000000);
   set_aggressive(0);
   
   set_chat_chance(10);
   load_chat("The Easter Bunny hops around the room.\n");
   load_chat("The Easter Bunny wiggles his nose.\n");
   load_chat("The Easter Bunny pinches your cheek!\n");
   
}

init() {
   
   ::init();
   
   add_action("ask_him","ask");
}
ask_him(arg) {
   if(arg == "bunny" || arg == "easter bunny"){
      write("The Easter Bunny gives you an egg!\n");
      MOCO("/players/jaraxle/xmas/gift_box.c"),TP);
      say("The Easter Bunny gives "+TPN+" an egg!\n");
      return 1; }
   write("You need to "+HIW+"ask bunny"+NORM+"\n");
}
