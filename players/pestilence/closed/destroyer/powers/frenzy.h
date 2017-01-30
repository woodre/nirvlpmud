frenzy(str) {
   object victim;
   string b1,b2;
   int Dam1;
   int ncost;
   int dam2, dam3, heh, bleh, dam4;
   int str_b;
   int myob;
   string *mess;
   string *mess2;
   string *mess3;
   object user;
   object wep;
   str_b = USER->query_attrib("str");
   dam2 = random(Dam1/2 + 15);
   dam3 = random(Dam1/2 + 10);
   dam4 = random(Dam1/3 + 20);
   user = environment(this_object());
   wep = user->query_weapon();

  myob = present("destroyer_ob", this_player());
  if(myob->query_spell_delay()) {
    write("You cannot cast a skill again so soon.\n"); return 1; }
   if(TP->query_spell_dam()) return 1;
if(this_player()->query_guild_rank() < 9){ write("You can't use this spell yet.\n"); return 1; }
    if (!str && !USER->query_attack()){
        write("You must be fighting to use this skill.\n");
        return 1;
    }
    if (!USER->query_attack()){
        write("You must be fighting to use this skill.\n");
        return 1;
    }
                if(USER->query_spell_point() < 50){
                        tell_object(USER, "You don't have enough energy for this skill.\n");
                        return 1;
                }
    if(TP->query_guild_rank() >= 10){
   Dam1 = (3*random(str_b)/2) + 14;
   }
   else{
   Dam1 = random(24) + 10;
   }   
      if (str) victim = present(str, environment(TP));
     else {
      victim = TP->query_attack();
      if(victim && !present(victim, environment(TP)))
        victim = 0;
     }
   if(!str && !victim) return 0;
   if(!victim) { write("That is not here.\n"); return 1; }

   if (!living(victim)){
      write("You cannot attack that!");
      say(TP->query_name() + " foolishly tries to attack "+ str+"\n");
      return 1;
   }
   if(!TP->query_weapon()){
     write("You must be wielding a weapon to attack in this style!\n");
     return 1;   
     }
   
   mess = wep->query_message_hit(dam2);
   mess2 = wep->query_message_hit(dam3);
   mess3 = wep->query_message_hit(dam4);
   if(TP->query_guild_rank() >= 10){
   ncost = 50;
   }
   else{      
   ncost = 24;
   }

   heh ="You begin to fight in a "+HIR+"f r e n z y"+NORM+".\nYou "+mess[1]+" "+victim->query_name()+""+mess[0]+".\nYou "+mess2[1]+" "+victim->query_name()+""+mess2[0]+".\nYou "+mess3[1]+" "+victim->query_name()+""+mess3[0]+".\nYou take a deep breathe and begin to fight normally.\n";
   bleh = TP->query_name()+" begins to fight in a "+HIR+"f r e n z y"+NORM+".\n"+TP->query_name()+" "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n"+TP->query_name()+" "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n"+TP->query_name()+" "+mess3[1]+" "+victim->query_name()+""+mess3[0]+".\n"+TP->query_name()+" slows down and regains form.\n";


/*
  myob->set_spell_delay(15);
*/

say(bleh);
TP->spell_object(victim, "frenzy", Dam1, ncost,
heh,
bleh,
""); 
   return 1;
}
