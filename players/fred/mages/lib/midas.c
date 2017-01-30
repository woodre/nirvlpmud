#include "/players/fred/mages/defs.h"

cmd_midas(){
 object body;
 int amt, bling;
 body = present("corpse", ENV(TP));
   if(!body) body = present("corpse", TP);
   if(!body){
     write("There is no corpse present to drain.\n"); return 1; }
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(INT < 20) {
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}   
   if(USER->query_sp() < 5){
     write("You don't have enough energy.\n"); return 1; }
   if(RANK < 1){
     write("You have not mastered this art yet.\n"); return 1; } 
   amt = body->heal_value();
   bling = (amt*(5+random(3)));
   TRU BOLD+BLK+"Dark Energy floods into the room..."+NORM+"\n");
   write("Your hand "+BOLD+YEL+"glows"+NORM+" a brilliant gold....\n"+
         "as you touch "+BOLD+BLK+body->short()+NORM+" it magically turns into "+bling+" gold coins.\n");
   say(TPN+"'s hand "+BOLD+YEL+"glows"+NORM+" a brilliant gold....\n"+
         "as "+PRO+" touches "+BOLD+BLK+body->short()+NORM+" it magically turns into gold coins.\n");
   destruct(body);
   USER->add_spell_point(-5);
   USER->add_money(bling);
   return 1;   
}
