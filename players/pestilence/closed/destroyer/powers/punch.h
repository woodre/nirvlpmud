punch(str) {
   object victim;
   string b1,b2;
   int Dam1, Dam2, Dam3;
   int ncost, str_b;
   string *mess;
   string *mess2;
   object user;
   object wep;
   str_b = USER->query_attrib("str");
   user = environment(this_object());
   wep = user->query_weapon();
   Dam2 = random(30);
   Dam3 = random(30);
if(this_player()->query_guild_rank() < 4){ write("You can't use this skill yet.\n"); return 1; }
    if (!str && !USER->query_attack()){
        write("You must be fighting to use this skill.\n");
        return 1;
    }
    if (!USER->query_attack()){
        write("You must be fighting to use this skill.\n");
        return 1;
    }
 
   if(TP->query_spell_dam()) return 1;
    if(USER->query_sp() < 20){
write("You don't have enough sps to maintain use of this skill.\n");
        return 1;
    }
   if(TP->query_guild_rank() >= 6){
   Dam1 = random(str_b) + 12;
   }
   else{
   Dam1 = random(str_b) + 8;
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
   
   mess = wep->query_message_hit(Dam2);
   mess2 = wep->query_message_hit(Dam3);
   if(TP->query_guild_rank() >= 6){
   ncost = 26;
   }
   else{      
   ncost = 20;
   }

    write("You "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n");
    say(TP->query_name()+" "+mess[1]+" "+victim->query_name()+""+mess[0]+".\n");
    USER->set_spell_dam(Dam1);
    USER->add_spell_point(-ncost);
    return 1;
}
