#include "/players/fred/mages/defs.h"

cmd_demise(){
 object victim;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(INT < 20){
     write("You don't have the intelligence needed cast this spell.\n"); return 1;}
   if(RANK < 3){ 
     write("You have not mastered this art yet.\n"); return 1;}   
   if(USER->query_sp() < 10){
     write("You don't have enough energy.\n"); return 1;}
   if(!USER->query_attack()){
     write("You must be in combat.\n"); return 1; }
   victim = USER->query_attack();
   if(ATT->is_player()){
     write("This isn't allowed on players.\n"); return 1;}
   if(ATT && ATT->query_hp() < 60){
    if((ATT->query_hp()*10)/(ATT->query_mhp()) < 1){
      write(BOLD+BLK+"You call upon the power of Shade as "+ATT->query_name()+BOLD+BLK+"'s power is low...\n\n"+
                 "       Shade willingly lends his power to you"+RED+"\n\n"+      
                 "        ~~~~~~~    D  E  A  T  H    ~~~~~~~"+BLK+"\n\n"+          
                 " overcomes "+ATT->query_name()+" as they collapse to the ground."+NORM+"\n");
      say(BOLD+BLK+TPN+" calls upon the power of Shade as "+ATT->query_name()+BOLD+BLK+"'s power is low...\n\n"+
               "          Shade willingly lends his power to "+TPN+RED+"\n\n"+
               "            ~~~~~~~   D  E  A  T  H   ~~~~~~~"+BLK+"\n\n"+
               " overcomes "+victim->query_name()+" as they collapse to the ground."+NORM+"\n");
        USER->add_spell_point(-10);
        victim->heal_self(-(ATT->query_hp()));
        victim->hit_player(100);
        return 1; }
     TOU BOLD+BLK+"\t"+ATT->query_name()+" is still too strong."+NORM+"\n");
     return 1; } 
   TOU BOLD+BLK+"\t"+ATT->query_name()+" is still too strong."+NORM+"\n");
   return 1; 
}
