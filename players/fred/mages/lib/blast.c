#include "/players/fred/mages/defs.h"

cmd_blast(str){
 object ob;
 string mess1, mess2, mess3;
 int damage;
 damage= 10+random(20);
  if(TP->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(LVL < 10){
    write("You need to be a higher level to cast this spell.\n"); return 1;}
  if(RANK < 2){
    write("You have not mastered this art yet.\n"); return 1;}
  if(TP->query_sp() < 20){
    write("You don't have enough energy.\n"); return 1;}
  if(TP->query_spell_dam()){ return 1;}
  if(!str && !TP->query_attack()){ write("Blast what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("You can't blast that!\n"); return 1;}
  switch(damage){
    case 26..100: 
      mess1 = "devastate";
      mess2 = " devastates";
      mess3 = " devastates";
      break;
    case 21..25: 
      mess1 = "wound"; 
      mess2 = " wounds";
      mess3 = " wounds"; 
      break;
    case 17..20:
      mess1 = "inflict pain upon";
      mess2 = " inflicts pain upon";
      mess3 = " inflicts pain upon";
      break;
    case 13..16:
      mess1 = "hit";
      mess2 = " hits";
      mess3 = " hits";
      break;
    case 10..12:
      mess1 = "graze";
      mess2 = " grazes";
      mess3 = " grazes";
      break;
      }
  damage *= 90;
  damage /= 100;
  TP->spell_object(ob,"dart", damage, 20,
      "You "+BOLD+RED+mess1+NORM+" "+ob->query_name()+" with a "+BOLD+BLK+"blast of Dark Energy"+NORM+".\n",
      TPN+BOLD+RED+mess2+NORM+" you with a "+BOLD+BLK+"blast of Dark Energy"+NORM+".\n",
      TPN+BOLD+RED+mess3+NORM+" "+ob->query_name()+" with a "+BOLD+BLK+"blast of Dark Energy"+NORM+".\n");
  TP->set_spell_dtype("other|dark");
      return 1;
  }
