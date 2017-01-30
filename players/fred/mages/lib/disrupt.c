#include "/players/fred/mages/defs.h"

cmd_disrupt(str) { 
 int damage;
 object ob; 
 string mess1, mess2, mess3;
 damage = 20+random(30);
  if(USER->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(INT < 25){
    write("You don't have the intelligence needed to cast this spell.\n"); return 1;}
  if(RANK < 5){
    write("You have not mastered this art yet.\n"); return 1;}
  if(LVL < 19){
    write("You need to be a higher level to cast this spell.\n"); return 1;}
  if(USER->query_sp() < 35){
    write("You don't have enough energy.\n"); return 1;}
  if(TP->query_spell_dam()){ return 1;}
  if(!str && !TP->query_attack()){ write("Disrupt what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("You can't disrupt that!\n"); return 1;}    
  switch(damage){
    case 47..100: 
      mess1 = "A N N I H I L A T E";
      mess2 = " A N N I H I L A T E S ";
      mess3 = " A N N I H I L A T E S ";
      break;
    case 39..46: 
      mess1 = "Destroy"; 
      mess2 = " Destroys";
      mess3 = " Destroys"; 
      break;
    case 32..38:
      mess1 = "severely wound";
      mess2 = " severely wounds";
      mess3 = " severely wounds";
      break;
    case 25..31:
      mess1 = "pummel";
      mess2 = " pummels";
      mess3 = " pummels";
      break;
    case 20..24:
      mess1 = "hit";
      mess2 = " hits";
      mess3 = " hits";
      break;
      }
  damage *= 90;
  damage /= 100;
  TP->spell_object(ob,"disrupt", damage, 35,
      "You "+BOLD+RED+mess1+NORM+" "+ob->query_name()+" with a "+BOLD+YEL+"DiSrUpTiOn rAy"+NORM+".\n",
      TPN+BOLD+RED+mess2+NORM+" you with a "+BOLD+YEL+"DiSrUpTiOn rAy"+NORM+".\n",
      TPN+BOLD+RED+mess3+NORM+" "+ob->query_name()+" with a "+BOLD+YEL+"DiSrUpTiOn rAy"+NORM+".\n");
  TP->set_spell_dtype("other|dark");
      return 1;
  }
