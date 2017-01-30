#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("shield") ;
   set_short(""+HIR+"Shield"+NORM+" of the"+NORM+" "+RED+"Dragon "+NORM+""+MAG+"Slayer"+NORM);
   set_long(""+CYN+"                                               \n"+
            "                                                \n"+
            "            _______________                 \n"+
            "            |******"+HIB+"=="+NORM+""+CYN+"******|                \n"+
            "            |******"+HIB+"||"+NORM+""+CYN+"******|                 \n"+
            "            |*****"+HIB+"===="+NORM+""+CYN+"*****|                \n"+
            "            |******"+RED+"||"+CYN+"******|                \n"+
            "            |******"+RED+"||"+CYN+"******|                \n"+
            "            |******"+RED+"||"+CYN+"******|                 \n"+
            "             \\*****"+RED+"||"+CYN+"*****/                \n"+
            "              \\****"+RED+"||"+CYN+"****/                 \n"+
            "               \\***"+RED+"\\/"+CYN+"***/                 \n"+
            "                \\******/        \n"+
            "                 \\****/               \n"+ 
            "                  \\**/                \n"+
            "                   \\/                          \n"+
            "                                "+NORM+"           \n");
   set_params("other|fire",0,25,0);      
   set_weight(2);
   set_value(10000);
   set_type("shield") ;
   set_ac(2) ;
}
