/* AC Bonuses go in here... Return tells how much of a bonus */

armor_special(){
   int bonus;
   if(earth_shield){
      tell_object(USER, "Your "+YEL+"rock-skin"+NORM+" protects you!\n");
      tell_room(environment(USER), capitalize(NAME)+"'s "+YEL+"rock-skin"+NORM+" protects "+USER->OBJ+" from harm.\n", ({ USER }));
      bonus += 4; }
   
   if(fire_shield){
      tell_object(USER, HIR+"Flames"+NORM+" enrage around your body, lashing at "+ATTN+"!\n");
      tell_room(environment(USER), HIR+"Flames"+NORM+" enrage around "+capitalize(NAME)+"'s body, lashing at "+ATTN+"!\n", ({ USER }));
      ATT->hit_player(5+random(6));
      bonus += 1; }
   
   if(water_shield){
      tell_object(USER, HIC+"Mists"+NORM+" of "+BLU+"water"+NORM+" deflect some of the blow..\n"+
         HIB+"Water "+NORM+CYN+"drizzles"+NORM+" over you, "+HIB+"healing"+NORM+" you somewhat.\n");
      tell_room(environment(USER), capitalize(NAME)+"'s "+HIC+"misty shield"+NORM+" protects "+USER+OBJ+" from "+ATTN+"'s attack.\n", ({ USER }));
      USER->add_hp(5+random(6));
      bonus +=1; }
   
   if(wind_shield){
      tell_object(USER, HIC+"Winds whip around your body deflecting "+ATTN+"'s humble attack.\n");
      tell_room(environment(USER), HIC+"Winds"+NORM+" whip around "+capitalize(NAME)+"'s body, deflecting "+ATTN+"'s humble attack.\n", ({ USER }));
      bonus +=2; }
   
   return 0;
}
