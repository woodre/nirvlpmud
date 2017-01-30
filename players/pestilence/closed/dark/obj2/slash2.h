static slash(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1;
   Dam1 = random(26);

    if (!str && !USER->query_attack()){
        write("Slash who???\n");
        return 1;
    }
   if(TP->query_spell_dam()) return 1;
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
case 21..100:
bash_mess1 = ""+HIR+"PULVERIZE"+NORM+"";
bash_mess2 = ""+HIR+"PULVERIZES"+NORM+"";
break;
case 17..20:
bash_mess1 = ""+HIR+"SLAM"+NORM+"";
bash_mess2 = ""+HIR+"SLAMS"+NORM+"";
break;
case 10..16:
bash_mess1 = "Strike";
bash_mess2 = "Strikes";
break;
case 5..9:
bash_mess1 = "Hit";
bash_mess2 = "Hits";
break;
case 1..4: 
bash_mess1 = "bruise";
bash_mess2 = "bruises";
break;
default:
bash_mess1 = "miss";
bash_mess2 = "misses";
break;
}
        
TP->spell_object(victim,"shield bash", Dam1,14,
   "You "+bash_mess1+" "+victim->query_name()+" with a slash.\n",
   TP->query_name()+" "+bash_mess2+" you with a slash.\n",
   "");
   return 1;
}
