main(str) {
   object victim;
   string b1,b2;
   string bash_mess1;
   string bash_mess2;
   int Dam1, str_bonus;
   Dam1 =   20 + random(40);
   
   if (environment()->query_attack()){
      write("You can't use this skill while already fighting.\n");
      return 1;
   }
   if (!str){
      write(""+YEL+"Blindside"+NORM+" who???\n");
      return 1; }
if(this_player()->query_guild_rank() < 5){ write("You can't use this spell yet.\n"); return 1; }
/*
   if(TP->query_spell_dam()) return 1;
*/
   /*
   if(this_player()->query_guild_rank() < 5){ write("You can't use this skill yet.\n"); return 1; }
   */
   if (str) victim = present(str, environment(TP));
   else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
         victim = 0;
   } 
   if(!victim) { write("That is not here.\n"); return 1; }
   
   if (!living(victim)) {
      write("You cannot attack that!\n");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
    if((victim->query_hp()*10)/(victim->query_mhp()) < 10){
        write(str+" is too weak for you to use this attack now.\n");
        return 1; }
   
   switch(Dam1){
      case 16..100:
      bash_mess1 = HIK+"You sneak around "+NORM+victim->query_name()+" and blindside them with a sickening crunch.\n";
      bash_mess2 = HIK+TP->query_name()+" sneaks around "+NORM+victim->query_name()+" and blindsides them with a sickening crunch.\n";
      break;
      case 7..15:
      bash_mess1 = HIK+"You weakly blindside"+NORM+" "+victim->query_name()+" with a weak hit.\n";
      bash_mess2 = HIK+TP->query_name()+" weakly blindsides "+victim->query_name()+" with a weak hit.\n";
      break;
      case 1..6:
      bash_mess1 = HIK+"You"+NORM+" miss "+victim->query_name()+" with a disgusting attempt to blindside.\n";
      bash_mess2 = HIK+TP->query_name()+NORM+" misses "+victim->query_name()+" with a distgusting attempt to blindside.\n";
      break;
      default:
      bash_mess1 = HIK+"You"+NORM+" miss "+victim->query_name()+" with a disgusting attempt to blindside.\n";
      bash_mess2 = HIK+TP->query_name()+NORM+" misses "+victim->query_name()+" with a distgusting attempt to blindside.\n";
      break;
   }
   say(bash_mess2);
   TP->spell_object(victim,"blindside", Dam1,33,
      bash_mess1,
      bash_mess2,
      "");
   
   return 1;
}
