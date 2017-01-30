inherit "/obj/treasure.c";
#include "/players/jaraxle/define.h"
reset(arg){
set_weight(1);
set_value(25+random(26));
}
short(){ return "Daize's List"; }
long(){ write("This is my list, treat it kindly.\n"+
              "\nFaKie HeAL .1. is for those who like\n"+
              "to have their cake and eat it too.\n"+
              "\nFaKie HeAL .2. is for those who do\n"+
              "not know what it means to have a\n"+
              "designated driver.\n"+
              "\nFaKie HeAL .3. is for those who\n"+
              "like to stray from the food chain.\n"+
              "\n                You're Welcome,\n"+
              "                   Daize.\n"); }
id(str){ return str == "list" || str == "daize's list"; }
query_save_flag(){      return 1;       }
