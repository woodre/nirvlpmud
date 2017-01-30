#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

int COLOR;
reset(arg)  {
switch(random(7)){
   case 0: COLOR = ""+HIR+"";
   break;
   case 1: COLOR = ""+HIB+"";
   break;
   case 2: COLOR = ""+HIC+"";
   break;
   case 3: COLOR = ""+HIM+"";
   break;
   case 4: COLOR = ""+HIY+"";
   break;
   case 5: COLOR = ""+HIG+"";
   break;
   case 6: COLOR = ""+HIW+"";
   break;
}
   if(arg) return;
   
   set_id("egg");
   set_alias("easter egg");
set_short(COLOR+"An easter egg"+NORM);
   set_long("A medium sized plastic "+COLOR+"easter egg"+NORM+". [ "+HIM+" What's inside?!"+NORM+" ]\n");
   set_weight(1);
   set_value(0);
}
init(){
   ::init();
   
   add_action("open","open");
   
}

open(arg){      
   int x;
   if(arg == "egg" || arg == "easter egg" || arg == "easter"){
      write("You crack open the "+COLOR+"egg"+NORM+" and get an "+COLOR+"easter gift"+NORM+"!\n");
      say(TPN+" opens an "+COLOR+"easter egg"+NORM+"!\n");
      switch(random(3)){
         case 0: x = "/players/jaraxle/xmas/free_beard.c";
         break;
         case 1: x = "/players/jaraxle/xmas/free_nose.c";
         break;
         case 2: x = "/players/jaraxle/xmas/free_hat.c";
         break;
      }
      MOCO(x), TP);
      destruct(this_object());
      return 1; }
   notify_fail("Open egg.\n"); return 0; }
query_save_flag(){ return 1; }
