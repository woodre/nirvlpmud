#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("tabard") ;
   set_alias("standard");
   set_short(""+NORM+"The "+HIR+"Great "+HIW+"Ta"+NORM+""+YEL+"ba"+HIW+"rd "+NORM+"of "+HIB+"["+HIM+"KINGS"+HIB+"]"+NORM);
   set_long(" "+HIW+"            __             __                  \n"+
            "            |##|           |##|                \n"+
            "            |###\\_________/###|                \n"+
            "            |#################|                \n"+
            "            |#################|                 \n"+
            "            |#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#"+NORM+""+YEL+"^"+HIW+"#|                \n"+
            "            |#"+NORM+""+HIR+"*"+NORM+""+YEL+"V"+HIY+"*"+NORM+""+YEL+"V"+HIG+"*"+NORM+""+YEL+"V"+HIB+"*"+NORM+""+YEL+"V"+HIM+"*"+NORM+""+YEL+"V"+HIW+"*"+NORM+""+YEL+"V"+RED+"*"+NORM+""+YEL+"V"+HIC+"*"+HIW+"#|                \n"+
            "            |#"+NORM+""+YEL+"HHHHHHHHHHHHHHH"+HIW+"#|                \n"+
            "            |#"+NORM+""+YEL+"HHHHHHH"+HIB+"*"+NORM+""+YEL+"HHHHHHH"+HIW+"#|                 \n"+
            "            |#"+NORM+""+YEL+"HHHHHH"+HIW+"*"+HIR+"*"+HIW+"*"+NORM+""+YEL+"HHHHHH"+HIW+"#|                \n"+
            "            |#"+NORM+""+YEL+"HHHHHHH"+HIB+"*"+NORM+""+YEL+"HHHHHHH"+HIW+"#|                 \n"+
            "            |#"+NORM+""+YEL+"HHHHHHHHHHHHHHH"+HIW+"#|                 \n"+
            "            |#################|                 \n"+
            "            |#################|               \n"+ 
            "             \\###############/                \n"+
            "              \\#############/                          \n"+
            "                                "+NORM+"           \n");
   set_params("other|unholy",0,10,0);
   set_params("other|evil",0,10,0);      
   set_weight(0);
   set_value(50000);
   set_type("chest") ;
   set_ac(1) ;
}
