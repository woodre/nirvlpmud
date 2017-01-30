#include "/players/dreamspeakr/closed/ansi.h"

inherit "obj/treasure";

reset(arg){
   if(arg) return;
  
   set_id("invitation");
   set_weight(1);
   
   set_short(HIR+"A wedding invitation"+NORM);
   set_long(HIR+" "+NORM+"\n"+      
      HIR+"     .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM+
      "\n"+
      HIW+"             You have been invited to a special event! \n"+NORM+
      "\n"+
      HIR+"       What:   "+HIW+"A celebration of love (wedding)\n"+NORM+
      HIR+"       When:   "+HIW+"NOW!!!  (Use this soon as it will disappear!)\n"+NORM+
      HIR+"       Where:  "+HIW+"The Chapel of Love\n"+NORM+
      "\n"+      
      HIR+"                 Another creation from Dreamspeakr\n"+NORM+
      "\n"+
      HIR+"     .:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:._.:*"+HIW+"~"+HIR+"*:.\n"+NORM+
      "\n");
}