#include "/players/fred/mages/defs.h"

cmd_coat(){
 object robes;
   if(USER->query_ghost()){ 
     write("You can't cast a spell in your condition.\n"); return 1; }
   if(INT < 20){
     write("You don't have the intelligence needed to cast this spell.\n"); return 1; }
   if(USER->query_sp() < 60) {
      write("You don't have enough energy.\n"); return 1; }
   if(present(ROBES,TP)){
      write("You are already protecting yourself.\n"); return 1; }    
   robes = CO("/players/fred/mages/obj/robes.c");
   MO(robes, TP);
   write("You empower your Death Robes with spectral energy.\n");
   say(capitalize(TPN)+"'s Black Robes are charged with spectral energy.\n");
   TP->add_spell_point(-60);
   return 1;}
   
