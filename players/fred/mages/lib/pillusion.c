#include "/players/fred/mages/defs.h"

cmd_pillusion(str) {
 object statue, who;
 string what;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}  
   if(!str){
     write("Who do you want to make an illusion of?\n"); return 1; }
   if(USER->query_sp() < 20) {
     write("You don't have enough energy.\n"); return 1;}   
   if(INT < 20){ 
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 2){ 
     write("You have not mastered this art yet.\n"); return 1;}
   who = find_player(str);
   if(!who){ write("You can't find that person.\n"); return 1;}
   if(who->query_invis()){ write("You can't find that person.\n"); return 1;}
   if(who->query_level() > 100){ write("You can't make an illusion of "+capitalize(str)+".\n"); return 1;}
   write(BOLD+BLK+"\tYou mutter a few ancient cantations...\n"+
          "\tDark Energy swirls around forming an illusion of a "+capitalize(str)+NORM+"\n");
    say(BOLD+BLK+"\t"+TPN+" mutters a few ancient cantations...\n"+
       "\tDark energy swirls around forming an illusion of a "+capitalize(str)+NORM+"\n");  
    what = who->short();
    statue = CO("/players/fred/mages/obj/illusion.c");
    MO(statue, ENV(TP));
    statue->set_short(what);
    statue->set_long("An illusion created by "+capitalize(TPN)+".\n");
    statue->set_alias(str);
    USER->add_spell_point(-20);
    return 1; 
   }
