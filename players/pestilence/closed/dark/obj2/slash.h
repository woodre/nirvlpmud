static slash(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1, str_bonus;
    str_bonus = present("dknight_ob",this_player())->query_combat();
   Dam1 = str_bonus+random(str_bonus*2);

   
   if(TP->query_spell_dam()) return 1;
    if (!str && !USER->query_attack()){
        write("Slash who???\n");
        return 1;
    }
   if(!USER->query_weapon()){
      tell_object(USER,
      "You must have a weapon wielded!\n");
      return 1;
      }
if(this_player()->query_guild_rank() < 3){ write("You can't use this spell yet.\n"); return 1; }
   if (str) victim = present(str, environment(TP));



     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }

switch(Dam1){
case 25..100:
bash_mess1 = "You "+HIR+"E V I C E R A T E"+NORM+" "+victim->query_name()+" with tremendous force.\n"+victim->query_name()+" screams out in Pain.\n";
bash_mess2 =TP->query_name()+" "+HIR+"E V I C E R A T E S"+NORM+" "+victim->query_name()+" with tremendous force.\n"+victim->query_name()+" screams out in Pain.\n";
break;
case 17..24:
bash_mess1 = "You visciously "+HIR+"lacerate"+NORM+" "+victim->query_name()+" with a tremendous slash.\n"+HIR+"B L O O D"+NORM+" splatters from "+victim->query_name()+"'s wound.\n";
bash_mess2 = TP->query_name()+" visciously "+HIR+"lacerates"+NORM+" "+victim->query_name()+" with a tremendous slash.\n"+HIR+"B L O O D"+NORM+" splatters from "+victim->query_name()+"'s wound.\n";
break;
case 10..16:
bash_mess1 = "You "+RED+"tear"+NORM+" into "+victim->query_name()+"'s flesh with a fierce slash.\n"+victim->query_name()+" stumbles from the blow.\n";
bash_mess2 = TP->query_name()+" "+RED+"tears"+NORM+" into "+victim->query_name()+"'s flesh with a fierce slash.\n"+victim->query_name()+" stumbles from the blow.\n";
break;
case 5..9:
bash_mess1 = ""+victim->query_name()+" "+HIR+"Bleeds"+NORM+" profusely from your demonic slash!\n";
bash_mess2 = ""+victim->query_name()+" "+HIR+"Bleeds"+NORM+" profusely from "+TP->query_name()+"'s demonic slash!";
break;
case 1..4: 
bash_mess1 = "You lightly "+BLU+"slice"+NORM+" "+victim->query_name()+" with a ferocious attack.\n";
bash_mess2 = TP->query_name()+" lightly "+BLU+"slices"+NORM+" "+victim->query_name()+" with a ferocious attack.\n";
break;
default:
bash_mess1 = "You clumsily miss "+victim->query_name()+" with a weak attempt of a slash.\n";
bash_mess2 = TP->query_name()+" clumsily misses "+victim->query_name()+" with a weak attempt of a slash.\n";
break;
}
say(bash_mess2+"");
Dam1 *= 90; Dam1 /= 100;
TP->spell_object(victim,"shield bash", Dam1,14,
""+bash_mess1+"",
""+bash_mess2+"",
"");
TP->set_spell_dtype("other|evil");
if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL IS: "+Dam1+" and your combat is "+str_bonus+".\n");
return 1;
}
