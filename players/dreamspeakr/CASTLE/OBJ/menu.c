#include "/players/dreamspeakr/closed/ansi.h"
inherit "/obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("menu");
   set_long("\n"+
      HIB+"\t ~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~\n"+
      "\t|"+HIW+"*"+HIB+"|                                                  |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|"+HIW+"           Welcome to Cloud Nine Tavern     "+NORM+HIB+"      |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|"+HIW+"         You can 'buy' the following here:        "+NORM+HIB+"|"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|                                                  |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|                      "+HIB+"Intox                       |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIB+"1.  A frothy mug of "+HIW+"ale"+NORM+"............."+HIC+"15"+NORM+HIB+"     |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIB+"2.  A tall glass of "+HIW+"house"+HIB+" wine"+NORM+"......"+HIC+"150"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIB+"3.  A tall glass of "+HIW+"fine"+HIB+" wine"+NORM+"......."+HIC+"250"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|                      "+HIR+"Food"+HIB+"                        |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIR+"4.  A handfull of fresh "+HIW+"berries"+NORM+"....."+HIC+"200"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIR+"5.  A leg of "+HIW+"lamb"+NORM+"..................."+HIC+"275"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|                      "+HIY+"Drink"+HIB+"                       |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIY+"6.  A cold glass of peach "+HIW+"nectur"+NORM+"...."+HIC+"175"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|       "+HIY+"7.  A warm cup of herbal "+HIW+"tea"+NORM+"........"+HIC+"250"+NORM+HIB+"    |"+HIW+"*"+HIB+"|\n"+
      "\t|"+HIW+"*"+HIB+"|                                                  |"+HIW+"*"+HIB+"|\n"+
      HIB+"\t ~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~"+HIW+"~~"+HIB+"~~\n"+NORM+
      "\n");
   set_value(0);
   set_weight(100);
}


get() { return 0; }

