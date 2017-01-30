#include "/players/tallos/ansi.h"
#include "/players/jaraxle/define.h"
inherit "obj/armor";

reset(arg){
   if(arg) return;
   ::reset(arg);
   set_name("shield") ;
   set_short(""+HIB+"A "+HIW+"White Shield "+HIB+"with a "+HIR+"Red Cross"+NORM);
   set_long(" "+HIW+"                                           \n"+
            "             ______________                 \n"+
            "            |**************|                \n"+
            "            |******"+HIR+"||"+HIW+"******|                 \n"+
            "            |******"+HIR+"||"+HIW+"******|                \n"+
            "            |*"+HIR+"||||||||||||"+HIW+"*|                \n"+
            "            |******"+HIR+"||"+HIW+"******|                \n"+
            "            |******"+HIR+"||"+HIW+"******|                 \n"+
            "             \\*****"+HIR+"||"+HIW+"*****/                \n"+
            "              \\****"+HIR+"||"+HIW+"****/                 \n"+
            "               \\***"+HIR+"||"+HIW+"***/                 \n"+
            "                \\**"+HIR+"||"+HIW+"**/        \n"+
            "                 \\*"+HIR+"||"+HIW+"*/               \n"+ 
            "                  \\**/                \n"+
            "                   \\/                          \n"+
            "                                "+NORM+"           \n");
   set_params("other|dark",0,15,0);
   set_params("other|evil",0,15,0);      
   set_weight(2);
   set_value(10000);
   set_type("shield") ;
   set_ac(2) ;
}
do_special(owner) {
   if(!random(7)) {
      tell_object(owner, "You feel "+HIR+"righteous"+NORM+" as the "+YEL+"sun"+NORM+" reflects"+NORM+" off your mirror polished "+HIW+"sh"+HIR+"ie"+HIW+"ld"+NORM+".\n");
    return 1;
   }
}