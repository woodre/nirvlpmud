#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = "Tower of the "+RED+"["+HIR+"Pho"+BLK+"e"+HIR+"nix"+NORM+RED+"]"+NORM+"("+HIC+"lost"+NORM+")";
   long_desc =
   "  Mist and darkness surround this strange area.\n"+
   "Everything around the area is warped as if the\n"+
   "entire room were wrapped in glass.\n";
}

init(){
   ::init();
   call_out("throne1", 5, TP);
}


throne1(){
   say("Swirls of mist spin around the room.\n");
   remove_call_out("throne1");
   call_out("throne2", 5, TP);
}

throne2(){
   say("You notice you're actually INSIDE the Key Sphere!\n");
   remove_call_out("throne2");
   call_out("throne3", 5, TP);
}

throne3(){
   say("You feel your body beginning to waver.\n");
   remove_call_out("throne3");
   call_out("throne4", 5, TP);
}

throne4(object who){
   say("You feel faint as the Sphere leaves you in a strange place.\n");
   who->move_player("without a trace#/players/jaraxle/closed/phoenix/rooms/throne");
   
return 1; }
