#include "/players/fred/mages/defs.h"

cmd_fog() {
 object  temp, ob;   
 int x, cost;
 x = 0;
 ob = all_inventory(ENV(TP));
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}   
   if(INT < 20) { 
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 2) { 
     write("You have not mastered this art yet.\n"); return 1;}  
   if(USER->query_attack()) cost = 25; 
   if(!USER->query_attack()) cost = (35+random(5));
   if(USER->query_sp() < cost) {
     write("You don't have enough energy.\n"); return 1;}   
   while(x<sizeof(ob)) {
      if(ob[x]->query_attack()) { 
      temp = ob[x]->query_attack();
      ob[x]->stop_fight();
      temp->stop_fight();
      temp->stop_fight();
      ob[x]->stop_fight();
      }
     x++;
    }
  write("You cast a "+BOLD+BLK+"Fog of cONfuSioN"+NORM+" spell calming all those around you.\n");
  say(TPN+" casts a "+BOLD+BLK+"Fog of cONfuSioN"+NORM+" spell calming all those around "+OBJ+".\n");
  USER->add_spell_point(-cost);
  return 1;
}
