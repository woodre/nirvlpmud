#include "/players/fred/mages/defs.h"
#include "/players/fred/mages/homedir/color.h"

cmd_obillusion(str){
  string what;
  object statue;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}  
   if(!str){
     write("What do you want to make an illusion of?\n"); return 1; }
   if(USER->query_sp() < 20) {
     write("You don't have enough energy.\n"); return 1;}   
   if(INT < 20){ 
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 2){ 
     write("You have not mastered this art yet.\n"); return 1;}
   statue = CO("/players/fred/mages/obj/illusion.c");
   MO(statue, ENV(TP));
   what= filter_msg(str);
   statue->set_short(capitalize(what));
   statue->set_long("An illusion created by "+capitalize(TPN)+".\n");
   statue->set_alias(str);
   write(BOLD+BLK+"\tYou mutter a few ancient cantations...\n"+
         "\tDark Energy swirls around forming an illusion of a "+capitalize(what)+NORM+"\n");
   say(BOLD+BLK+"\t"+TPN+" mutters a few ancient cantations...\n"+
       "\tDark energy swirls around forming an illusion of a "+capitalize(what)+NORM+"\n"); 
   USER->add_spell_point(-20);
   return 1;
}
