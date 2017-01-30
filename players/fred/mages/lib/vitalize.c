#include "/players/fred/mages/defs.h"

cmd_vitalize(str){
 int amt,garg,stuff;
   amt = str;
   if(!str){
     write("How much energy would you like to transfer?\n"); return 1;}
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}   
   if(sscanf(str, "%d", amt) !=1){
     write("How much energy would you like to transfer?\n"); return 1;}
   if(USER->query_hp() < amt) {
     write("You are too weak to transfer "+amt+"\n"); return 1;}
   if(amt < 10){
     write("You have to vitalize at least 10.\n"); return 1;}
   if(RANK < 2){
     write("You have not mastered this art yet.\n"); return 1; }
   stuff = (amt/10);
   USER->add_hit_point(-amt);
   USER->add_spell_point(amt-stuff);
   write("You draw "+BOLD+YEL+"energy"+NORM+" from within your body.\n");
   say(capitalize(TPN)+" draws "+BOLD+YEL+"energy"+NORM+" for magic from a physical self.\n");
   return 1;
}
