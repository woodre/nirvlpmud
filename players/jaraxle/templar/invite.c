#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
}
id(str){ return str == "KnightInvite" || str == "invite"; }
drop(){
destruct(this_object());
}

