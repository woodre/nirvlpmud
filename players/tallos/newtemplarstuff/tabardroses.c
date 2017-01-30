#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("tabard") ;
   set_alias("standard");
   set_short(""+HIW+"Tabard "+NORM+"of "+HIB+"["+NORM+""+GRN+"-,'-{"+RED+"@ "+MAG+"R"+HIW+"O"+HIY+"S"+HIC+"E"+HIM+"S "+NORM+""+RED+"@"+GRN+"}-',-"+HIB+"]"+NORM);
   set_long(" "+HIW+"            __             __                  \n"+
            "            |##|           |##|                \n"+
            "            |###\\_________/###|                \n"+
            "            |#################|                \n"+
            "            |##"+NORM+""+GRN+"-,'-{"+RED+"@"+HIW+"#########|                 \n"+
            "            |###"+NORM+""+GRN+"-,'-{"+MAG+"@"+HIW+"########|                \n"+
            "            |####"+NORM+""+GRN+"-,'-{"+HIY+"@"+HIW+"#######|                \n"+
            "            |#######"+HIC+"@"+NORM+""+GRN+"}-',-"+HIW+"####|                \n"+
            "            |########"+HIB+"@"+NORM+""+GRN+"}-',-"+HIW+"###|                 \n"+
            "            |#########"+HIC+"@"+NORM+""+GRN+"}-',-"+HIW+"##|                \n"+
            "            |##"+NORM+""+GRN+"-,'-{"+HIM+"@"+HIW+"#########|                 \n"+
            "            |###"+NORM+""+GRN+"-,'-{"+HIR+"@"+HIW+"########|                 \n"+
            "            |####"+NORM+""+GRN+"-,'-{"+BLU+"@"+HIW+"#######|                 \n"+
            "            |#################|               \n"+ 
            "             \\###############/                \n"+
            "              \\#############/                          \n"+
            "                                "+NORM+"           \n");      
   set_weight(0);
   set_value(50000);
   set_type("chest") ;
   set_ac(1) ;
}
