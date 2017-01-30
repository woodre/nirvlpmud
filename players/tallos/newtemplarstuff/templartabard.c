#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("tabard") ;
   set_alias("standard");
   set_short(""+HIB+"Grand"+HIW+" Ta"+HIR+"ba"+HIW+"rd "+NORM+"of the "+HIB+"["+HIG+"Knights Templar"+HIB+"]"+NORM);
   set_long(" "+HIW+"            __             __                  \n"+
            "            |##|           |##|                \n"+
            "            |###\\_________/###|                \n"+
            "            |#################|                \n"+
            "            |#######"+HIR+"||"+HIW+"########|                 \n"+
            "            |#######"+HIR+"||"+HIW+"########|                \n"+
            "            |#######"+HIR+"||"+HIW+"########|                \n"+
            "            |##"+HIR+"|||||||||||||"+HIW+"##|                \n"+
            "            |#######"+HIR+"||"+HIW+"########|                 \n"+
            "            |#######"+HIR+"||"+HIW+"########|                \n"+
            "            |#######"+HIR+"||"+HIW+"########|                 \n"+
            "            |#######"+HIR+"||"+HIW+"########|                 \n"+
            "            |#######"+HIR+"||"+HIW+"########|                 \n"+
            "            |#######"+HIR+"||"+HIW+"########|               \n"+ 
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
