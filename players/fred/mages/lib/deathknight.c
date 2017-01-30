#include "/players/fred/mages/defs.h"

cmd_deathknight(){
 object knight, me;
 string name;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(USER->dknighted()){
     write("You are already a Deathknight.\n"); return 1;}
   if(USER->liched()){
     write("You are already a Lich.\n"); return 1;}
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 5){  
     write("You have not mastered this art yet.\n"); return 1;}   
   if(TP->query_sp() < 100) {
     write("You don't have enough energy.\n"); return 1;}
   me = TP;
   USER->add_spell_point(-100);
   write(BOLD+RED+"\n\tYou transform into an awesome Deathknight.\n"+NORM);
   say(BOLD+RED+capitalize(TPRN)+" transforms into an awesome Deathknight.\n"+NORM);
   name = TPRN;
   knight = CO("/players/fred/mages/obj/deathknight.c");
   knight->do_shadow(me);
   knight->set_name(name);
   knight->set_time(LVL+(XLVL/4));
   return 1; 
 }

