#include "/players/jaraxle/define.h"
inherit "/obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("bandage");
   set_alias("bandages");
   set_short("A pile of bandages");
   set_long("A pile of dirty bandages.\n"+
      "These bandages can be "+BLK+BOLD+"bartered"+NORM+" with "+YEL+"any"+NORM+" merchant.\n");
   set_weight(1);
   set_value(3500+random(1000));
}
init(){
   ::init();
   
   add_action("barter","barter");
   
}

barter(arg){      
   
   int cost, bandages, WHO;
   
   switch(random(5)){
      case 0: WHO = "Madam Rue"; break;
      case 1: WHO = "Sedjak"; break;
      case 2: WHO = "Pawnbroker"; break;
      case 3: WHO = "Gurther"; break;
      case 4: WHO = "merchant"; break;
      return 1; }
   
   bandages = present("bandages",environment(TO));
   cost = bandages->query_value();
   
   if(arg == "bandages" || arg == "bandage"){ 
      
 if(!present("sedjak",environment(TP)) && !present("merchant",environment(TP))  && !present("pawnbroker",environment(TP)) && !present("rue",environment(TP)) && !present("gurther",environment(TP))){
         write("Only someone like "+BOLD+""+WHO+" "+NORM+"would be interested in these.\n");
         return 1; }
      
      if(present("sedjak",environment(TP))){
         write("Sedjak haggles with you, eventually giving you "+HIY+""+ cost +""+NORM+" coins for the bandages.\n"); }
      
      if(present("gurther",environment(TP))){
         write("The gurther haggles with you, eventually giving you "+HIY+""+ cost +""+NORM+" coins for the bandages.\n"); }
      
      if(present("rue",environment(TP))){
         write("Madam Rue barters with you, eventually giving you "+HIY+""+ cost +""+NORM+" coins for the bandages.\n"); }
      
      if(present("shopkeeper",environment(TP))){
         write("The Pawnbroker gives you "+HIY+""+ cost +""+NORM+" coins for the bandages.\n"); }
    if(present("merchant",environment(TP))){
         write("The Merchant gives you "+HIY+""+ cost +""+NORM+" coins for the bandages.\n"); }
      call_other(this_player(), "add_money", cost);
      destruct(bandages);
      return 1; }
   notify_fail("Barter what?\n"); return 0; }

