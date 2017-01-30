#include "/players/fred/mages/defs.h"

cmd_bede(str){
   object gp;   
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(USER->query_sp() < 200){
      write("You don't have enough energy.\n"); return 1;}   
   if(INT < 30) { 
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 5) { 
     write("You have not mastered this art yet.\n"); return 1;}
   gp = present("ghost of "+str, ENV(TP));
   if(!gp){
     write("You don't see "+str+" here.\n");
     return 1; }
   TE(gp, BOLD+BLK+"\n\n"+
      "\tYour soul enters the Negative Plane.\n"+
      "\tYou are pulled through the Ether of Existence.\n"+
      "\tYou are restored.\n\n\n"+NORM);
       MO(gp, ENV(TP));
   USER->add_spell_point(-200); 
   write(BOLD+BLK+"The ground begins to shake....\n"+
        "Dark Energy engulfs "+capitalize(str)+"!\n"+
        ""+capitalize(str)+" screams in agony as "+gp->query_possessive()+" body is restored.\n"+NORM);
   say(BOLD+BLK+"The ground begins to shake....\n"+
        "Dark Energy engulfs "+capitalize(str)+"!\n"+
        ""+capitalize(str)+" screams in agony as "+gp->query_possessive()+" body is restored by "+TPN+".\n"+NORM);
   return call_other(gp, "remove_ghost", 0);
   return 1;
}
