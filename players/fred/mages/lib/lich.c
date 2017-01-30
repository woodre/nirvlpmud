#include "/players/fred/mages/defs.h"

cmd_lich(){
 object me, lich;
 string name;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(USER->query_sp() < 60) {
     write("You don't have enough energy.\n"); return 1;}   
   if(INT < 20){ 
     write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
   if(RANK < 3){ 
     write("You have not mastered this art yet.\n"); return 1;}
   if(USER->liched()){
     write("You already are a Lich.\n"); return 1;}
   if(USER->dknighted()){
     write("You are already a Deathknight.\n"); return 1;}
   me = this_player();
   USER->add_spell_point(-60);
   write(BOLD+RED+"\n\tYou transform into a horrible lich.\n"+NORM);
   say(BOLD+RED+capitalize(TPRN)+" transforms into a horrible lich.\n"+NORM);
   name = this_player()->query_real_name();
   lich = clone_object("/players/fred/mages/obj/lich.c");
   lich->do_shadow(me);
   lich->set_name(name);
   lich->set_time(LVL+(XLVL/4));
   return 1;
}

