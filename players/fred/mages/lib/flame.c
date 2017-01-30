#include "/players/fred/mages/defs.h"

cmd_flame(str){
 object ob;
 string mess1, mess2, mess3;
 int damage;
 damage = 10+random(30);
   if(USER->query_ghost()){
     write("You can't cast a spell in your condition.\n"); return 1;}
   if(LVL < 15){
     write("You need to be a higher level to cast this spell.\n"); return 1;}
   if(USER->query_sp() < 25){
     write("You don't have enough energy.\n"); return 1;}
   if(RANK < 3){
     write("You have not mastered this art yet.\n"); return 1; }
   if(TP->query_spell_dam()){ return 1;}
   if(!str && !TP->query_attack()){ write("What would you like to cast flame on?\n"); return 1;}
   if(!str) ob = TP->query_attack();
   if(!ob) ob = present(str, ENV(TP));
   if(!ob || !present(ob, ENV(TP))){
     write("You don't see "+str+" here.\n"); return 1;}
   if(!living(ob)){
     write("You can't cast flame upon that!\n"); return 1;}
   switch(damage){
     case 33..100:
       mess1 = "summon a giant ball of "+BOLD+RED+"flame"+NORM+" that "+BOLD+RED+"engulfs "+NORM+ob->query_name()+"";
       mess2 = " summons a giant ball of "+BOLD+RED+"flame"+NORM+" that "+BOLD+RED+"engulfs"+NORM+" you";
       mess3 = " summons a giant ball of "+BOLD+RED+"flame"+NORM+" that "+BOLD+RED+"engulfs "+NORM+ob->query_name()+"";
       break;
     case 25..32:
       mess1 = "burn "+ob->query_name()+" with a large "+BOLD+RED+"flame"+NORM+" blast";
       mess2 = " burns you with a large "+BOLD+RED+"flame"+NORM+" blast";
       mess3 = " burns "+ob->query_name()+" with a large "+BOLD+RED+"flame"+NORM+" blast";
       break;
     case 18..24:
       mess1 = ""+BOLD+RED+"scorch "+NORM+ob->query_name()+" with a "+BOLD+RED+"ball of flame"+NORM+"";
       mess2 = ""+BOLD+RED+" scorches"+NORM+" you with a "+BOLD+RED+"ball of flame"+NORM+"";
       mess3 = ""+BOLD+RED+" scorches "+NORM+ob->query_name()+" with a "+BOLD+RED+"ball of flame"+NORM+"";
       break;
     case 10..17:
       mess1 = ""+HIR+"singe "+NORM+ob->query_name()+" with a flame blast";
       mess2 = ""+HIR+" singes "+NORM+" you with a flame blast";
       mess3 = ""+HIR+" singes "+NORM+ob->query_name()+" with a flame blast";
       break;
     }
  damage *= 90;
  damage /= 100;
   TP->spell_object(ob,"flame",damage,25,
       "You "+mess1+".\n",
       ""+TPN+mess2+".\n",
       ""+TPN+mess3+".\n");
   TP->set_spell_dtype("other|fire");
       return 1;
   }
