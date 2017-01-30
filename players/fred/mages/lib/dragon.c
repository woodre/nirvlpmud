#include "/players/fred/mages/defs.h"

cmd_dragon(str) {
 object dragon, me, ob;
 int dragoned, ghouled;
 string dname;
 me = TP;   
 ob = present("dark_circle", TP);
 dragoned = query_has_dragon();
 ghouled = query_has_ghoul();
  if(dragoned != 0){
    write("You already have a dragon.\n"); return 1; }
  if(ghouled != 0){
    write("You are only allowed to use one pet at a time.\n"); return 1; }
  if(USER->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(INT < 20) {
    write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
  if(USER->query_sp() < 100) {
    write("You don't have enough energy.\n"); return 1;}
  if(RANK < 4){
    write("You have not mastered this art yet.\n"); return 1;}
  MO(CO("/players/fred/mages/mon/shadowdragon.c"), ENV(TP));
  write("\n  A large "+BOLD+BLK+"Shadow Dragon"+NORM+" swoops down from the sky and lands next to you.\n");
  say("A large "+BOLD+BLK+"Shadow Dragon"+NORM+" swoops down from the sky and lands next to "+TPN+".\n");
  dname = ob->query_dragon_name(); 
  dragon = present("dragon", ENV(TP));
  dragon->patch_owner(me);
  if(dname != 0){
  dragon->set_name(dname);
  dragon->set_short(BOLD+BLK+capitalize(dname)+" the Shadowdragon"+NORM+" (lord of evil)"); }
  dragon->init();
  ob->set_has_dragon(1);
  ob->ssave();
  TP->add_spell_point(-100); 
  return 1;
}
