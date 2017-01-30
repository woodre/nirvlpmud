#include "/players/fred/mages/defs.h"

cmd_drain(str){
 object body;
 int amt;
 body = present("corpse", ENV(TP));
   if(!body) body = present("corpse", TP);
   if(!body){ write("There is no corpse present to drain.\n"); return 1; }
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(INT < 20) {
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}   
   if(USER->query_sp() < 5){
     write("You don't have enough energy.\n"); return 1; }
   if(RANK < 1){
     write("You have not mastered that art yet.\n"); return 1; }
   amt = body->heal_value();
   TRU BOLD+BLK+"Dark Energy floods into the room..."+NORM+"\n");
   write("You place your hand on "+BOLD+BLK+body->short()+"'s"+NORM+" chest\n"+
         "  and feel dark energy surge through your body.\n");
   say(TPN+" places "+POS+" hand on "+BOLD+BLK+body->short()+"'s"+NORM+" chest\n"+
           ""+TPN+"'s body shakes as "+PRO+" drains the energy from "+BOLD+BLK+body->short()+NORM+"\n");
   destruct(body);
   USER->heal_self(amt);
   return 1;   
}
