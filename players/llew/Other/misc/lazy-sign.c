#include "/players/llew/closed/ansi.h"
inherit "/obj/treasure";

reset(arg) {
   if(arg) return;
   set_id("menu");
   set_short("A large wooden menu hanging on the wall");
   set_long("\n"+
      GRN+"\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+
      "\t|                                                      |\n"+
      "\t|"+HIW+"         Welcome to Lazy Llew's Bar, a place   "+NORM+GRN+"       |\n"+
      "\t|"+HIW+"           to relax in comfort and peace. "+NORM+GRN+"            |\n"+
      "\t|                                                      |\n"+
      "\t|                                                      |\n"+
      "\t|"+HIB+"    Alcoholic beverages:    "+NORM+GRN+"                          |\n"+
      "\t|       "+BLU+"Ale"+NORM+"..............."+CYN+"15"+NORM+BLU+"   Whiskey"+NORM+".........."+CYN+"235"+NORM+GRN+"    |\n"+
      "\t|       "+BLU+"Brandy"+NORM+"..........."+CYN+"150"+NORM+BLU+"   Twilsden"+NORM+"........."+CYN+"500"+NORM+GRN+"    |\n"+
      "\t|                                                      |\n"+
      "\t|"+HIB+"    Food:  "+NORM+GRN+"                                           |\n"+
      "\t|       "+BLU+"Cheese"+NORM+"..........."+CYN+"125"+NORM+BLU+"   Meat Stew"+NORM+"........"+CYN+"275"+NORM+GRN+"    |\n"+
      "\t|       "+BLU+"Bread"+NORM+"............"+CYN+"200"+NORM+BLU+"   Salmon"+NORM+"..........."+CYN+"500"+NORM+GRN+"    |\n"+
      "\t|                                                      |\n"+
      "\t|"+HIB+"    Beverages: "+NORM+GRN+"                                       |\n"+
      "\t|       "+BLU+"Water"+NORM+"............."+CYN+"25"+NORM+BLU+"   Nectar"+NORM+"..........."+CYN+"250"+NORM+GRN+"    |\n"+
      "\t|       "+BLU+"Goat's Milk"+NORM+"......"+CYN+"175"+NORM+BLU+"   Ipocras"+NORM+".........."+CYN+"500"+NORM+GRN+"    |\n"+
      "\t|                                                      |\n"+
      "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+
      "\n");
   set_value(0);
   set_weight(100);
}


get() { return 0; }
