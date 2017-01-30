static torment(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1, str_bonus;
   str_bonus = present("dknight_ob",this_player())->query_combat();
   Dam1 = 4 + (random(str_bonus*4)+ random(5));

 
    if(TP->query_spell_dam()) return 1;
    if (!str && !USER->query_attack()){
        write(""+HIK+"Torment"+NORM+" who???\n");
        return 1; }
if(this_player()->query_guild_rank() < 5){ write("You can't use this spell yet.\n"); return 1; }
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
case 39..100:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"O B L I T E R A T E S "+NORM+victim->query_name()+" with a sickening unnatural force.\n"+HIR+"BLOOD"+NORM+" begins to pour from "+victim->query_name()+"'s head.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"O B L I T E R A T E S "+NORM+victim->query_name()+" with a sickening unnatural force.\n"+HIR+"BLOOD"+NORM+" begins to pour from "+victim->query_name()+"'s head.\n";
break;
case 25..38:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"RUPTURES"+NORM+" "+victim->query_name()+"'s organs with extreme force.\n"+victim->query_name()+" writhes in pain.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"RUPTURES"+NORM+" "+victim->query_name()+"'s organs with extreme force.\n"+victim->query_name()+" writhes in pain.\n";
break;
case 12..24:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" "+HIR+"Eviscerates"+NORM+" "+victim->query_name()+" with an insane force.\n"+victim->query_name()+"'s guts seep out slowly, letting "+HIR+"blood"+NORM+" flow freely.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" "+HIR+"Eviscerates"+NORM+" "+victim->query_name()+" with an insane force.\n"+victim->query_name()+"'s guts seep out slowly, letting "+HIR+"blood"+NORM+" flow freely.\n";
break;
case 5..11:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" destroys "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" destroys "+victim->query_name()+" with an unatural force.\n";
break;
case 1..4: 
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" hits "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" hits "+victim->query_name()+" with an unatural force.\n";
default:
bash_mess1 = HIK+"Darkness"+NORM+" swirls around you.\n"+HIK+"Darkness"+NORM+" misses "+victim->query_name()+" with an unatural force.\n";
bash_mess2 = HIK+"Darkness"+NORM+" swirls around "+TP->query_name()+".\n"+HIK+"Darkness"+NORM+" misses "+victim->query_name()+" with an unatural force.\n";
break;
}
say(bash_mess2);
Dam1 *= 900; Dam1 /= 1000;
TP->spell_object(victim,"torment", Dam1,30,
bash_mess1,
bash_mess2,
"");
TP->set_spell_dtype("other|evil");
if(USER->query_real_name() == "pestilence") tell_object(USER, "TOTAL IS: "+Dam1+" and your combat is "+str_bonus+".\n");
return 1;
}

