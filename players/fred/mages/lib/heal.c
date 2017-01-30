#include "/players/fred/mages/defs.h" 

cmd_heal(str) {
 object ob;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1; }
   if(USER->query_sp() < 20){
     write("You don't have enough energy.\n"); return 1;}
   if(RANK < 1){
     write("You have not mastered this art yet.\n"); return 1;}
   if(!str) ob = TP;
   if(!ob) ob = present(str, ENV(TP));
   if(!ob){
     write("You don't see that person here.\n"); return 1; }
   if(!living(ob)){
     write("You can't heal that.\n"); return 1;}
   write("You cast a healing spell upon "+ob->query_name()+"\n");
   say(capitalize(TPRN)+" casts a healing spell upon "+ob->query_name()+"\n");
   USER->add_spell_point(-20);
   ob->add_hit_point(random(TP->query_level())+10);
   return 1;  
 }

