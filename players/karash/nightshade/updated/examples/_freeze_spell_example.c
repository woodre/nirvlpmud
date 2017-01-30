#include "/players/fred/mages/defs.h"

cmd_freeze(str) {
object ob, ice;
int x;
 x = (60 - (LVL+(XLVL/4)));
  if(USER->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(INT < 25) {
    write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
  if(RANK < 4) { 
    write("You have not mastered this art yet.\n"); return 1;}
  if(USER->query_sp() < x) {
    write("You don't have enough energy.\n"); return 1;}      
  if(!str && !TP->query_attack()){ write("Freeze what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("You can't freeze that!\n"); return 1;}
  if(ob->is_player()){
    write("You can't freeze players.\n"); return 1;}
  if(ob->froze()){
    write(ob->query_name()+" is already frozen.\n"); return 1; }
  ice = CO("/players/fred/mages/obj/freeze.c");   
  ice->set_time(LVL);
  ice->do_shadow(ob);
  write("You summon a "+BOLD+BLK+"CyClonE of fRosT"+NORM+" freezing "+ob->query_name()+" in time.\n");
  say(TPN+" summons a "+BOLD+BLK+"CyClonE of fRosT"+NORM+" freezing "+ob->query_name()+" in time.\n");
  USER->add_spell_point(-x);  
  return 1;
}
