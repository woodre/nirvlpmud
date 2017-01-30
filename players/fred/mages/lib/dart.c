#include "/players/fred/mages/defs.h"

cmd_dart(str){
 object ob;
 string mess1, mess2, mess3;
 int damage;
 damage=random(20);
  if(TP->query_ghost()){
    write("You can't cast a spell in your condition.\n"); return 1;}
  if(LVL < 5){
    write("You need to be a higher level to cast this spell.\n"); return 1;}
  if(TP->query_sp() < 10){
    write("You don't have enough energy.\n"); return 1;}
  if(TP->query_spell_dam()){ return 1;}
  if(!str && !TP->query_attack()){ write("Dart what?\n"); return 1; }
  if(!str) ob = TP->query_attack();
  if(!ob) ob = present(str, ENV(TP));
  if(!ob || !present(ob, ENV(TP))){
    write("You don't see "+str+" here.\n"); return 1; }
  if(!living(ob)){
    write("You can't dart that!\n"); return 1;}
  switch(damage){
    case 17..100: 
      mess1 = "launch a death dart deep into "+ob->query_name()+"'s heart";
      mess2 = " launches a death dart deep into your heart";
      mess3 = " launches a death dart deep into "+ob->query_name()+"'s heart";
      break;
    case 14..16: 
      mess1 = "slam a death dart into "+ob->query_name()+"'s chest"; 
      mess2 = " slams a death dart into your chest";
      mess3 = " slams a death dart into "+ob->query_name()+"'s chest"; 
      break;
    case 11..13:
      mess1 = "strike "+ob->query_name()+" with a well placed death dart";
      mess2 = " strikes you with a well placed death dart";
      mess3 = " strikes "+ob->query_name()+" with a well placed death dart";
      break;
    case 7..10:
      mess1 = "hit "+ob->query_name()+" with a death dart";
      mess2 = " hits you with a death dart";
      mess3 = " hits "+ob->query_name()+" with a death dart";
      break;
    case 3..6:
      mess1 = "graze "+ob->query_name()+" with a death dart";
      mess2 = " grazes you with a death dart";
      mess3 = " grazes "+ob->query_name()+" with a death dart";
      break;
    case 1..2:
      mess1 = "nick "+ob->query_name()+" with a death dart";
      mess2 = " nicks you with a death dart"; 
      mess3 = " nicks "+ob->query_name()+" with a death dart";
      break;
    default:
      mess1 = "watch as your death dart sails past "+ob->query_name()+"";
      mess2 = " throws a death dart over your head";
      mess3 = " throws a death dart over "+ob->query_name()+"'s head";
      break;
      }
  damage *= 90;
  damage /= 100;
  TP->spell_object(ob,"dart", damage, 10,
      BOLD+BLK+"You "+mess1+NORM+".\n",
      BOLD+BLK+TPN+mess2+NORM+".\n",
      BOLD+BLK+TPN+mess3+NORM+".\n");
  TP->set_spell_dtype("other|dark");
      return 1;
  }
