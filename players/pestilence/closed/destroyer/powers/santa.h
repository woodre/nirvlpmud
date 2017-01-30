#include "/players/pestilence/define.h"

cmd_santa(){
 object me, lich;
 string name;
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
if(this_player()->query_guild_rank() < 10){ write("You can't use this skill yet.\n"); return 1; }
   if(USER->query_sp() < 150) {
     write("You don't have enough energy.\n"); return 1;}   
   if(USER->liched()){
     write("You already are a Predator.\n"); return 1;}
   if(USER->dknighted()){
     write("You are already a Deathknight.\n"); return 1;}
   me = this_player();
   USER->add_spell_point(-150);
   write(BOLD+RED+"\n\tYou transform into Predator Mode.\n"+NORM);
   say(BOLD+RED+capitalize(TPRN)+" has transformed into Predator Mode.\n"+NORM);
   name = HIR+"Santa "+HIW+"Claus"+NORM;
   lich = clone_object("/players/pestilence/closed/destroyer/obj/shadow2.c");
   lich->do_shadow(me);
   lich->set_name(name);
   lich->set_time(140);
   return 1;
}
