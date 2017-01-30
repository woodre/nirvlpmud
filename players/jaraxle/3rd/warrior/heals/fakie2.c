inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
set_weight(0);
set_value(5);
}
short(){ return ""+HIW+"F"+HIC+"a"+HIB+"K"+HIG+"i"+HIR+"e "+BLK+"H"+HIY+"e"+NORM+BLU+"A"+YEL+"L"+NORM+" ."+HIB+"2"+NORM+""; }
long(){ write("A fake heal for heal types ."+HIB+"2"+NORM+".\nYou can use '"+HIW+"sneakheal"+NORM+"' to place it onto another player.\nYou can also '"+HIW+"cash"+NORM+"' it in.\n"); }
id(str){ return str == "heal" || str == "fakie heal"; }
query_save_flag(){      return 1;       }


init(){
   ::init();
   add_action("HEALME","drink");
   add_action("HEALME","slam");
   add_action("HEALME","sip");
   add_action("HEALME","gulp");
  add_action("cashme","cash");
}

HEALME(arg){
if(arg != "THIS IS NOT COOL"){
write(HIB+BLINK+"YOU JUST TRIED TO USE A FAKIE HEAL!\n"+NORM); 
write("The FaKie HeAL disintegrates.\n");
destruct(this_object());
return 1; }
}
cashme(arg){
if(arg == "fakie heal" || arg == "heal"){
write("You cash in the FaKie HeAL for "+HIY+"coins"+NORM+".\n");
this_player()->add_money(100+random(1401));
destruct(this_object());
return 1; }
write("Cash what?\n");
return 1; }

