
/*
 * ASSESS (3/19/94)
 * Get an idea of monster's level, health, armor class, weapon class
 */

assess(who) {
   object target;
   string ac_msg, wc_msg, lvl_msg, health_msg;

   if(!who && !this_player()->query_attack())
     notify_fail("Who would you like to assess?");
   if(!who)
     target = this_player()->query_attack();
   else
     target = present(who, environment(this_player()));
   if(!who)
     who = target->query_name();
   if(!target || !living(target)) 
     notify_fail(capitalize(who)+" is not here.");
   ac_msg = get_ac_msg(target->query_ac());
   wc_msg = get_wc_msg(target->query_wc());
   lvl_msg = get_level_msg(target->query_level());
   health_msg = get_health_msg(target->query_hp(),target->query_mhp());
   TELL(capitalize(this_player()->query_name())+" studies "+
        capitalize(who)+" intently.\n");
   write("\n");
   write("====> "+target->short()+"\n");
   write("      "+justify("Skill:",12)+lvl_msg+".\n");
   write("      "+justify("Weapons:",12)+wc_msg+".\n");
   write("      "+justify("Armor:",12)+ac_msg+".\n");
   write("      "+justify("Health:",12)+health_msg+".\n");
   return 1;
}

get_ac_msg(ac) {
   if(!ac)
     return "Not protected";
   if(ac <= 2)
     return "Slightly protected";
   if(ac <= 5)
     return "Well protected";
   if(ac <= 9)
     return "Very well protected";
   if(ac <= 14)
     return "Extremely well protected";
   if(ac > 14)
     return "Exceptionally well protected";
}

get_wc_msg(wc) {
   if(!wc)
     return "Unarmed";
   if(wc <= 10)
     return "Poorly armed";
   if(wc <= 14)
     return "Well armed";
   if(wc <= 18)
     return "Very well armed";
   if(wc <= 25)
     return "Extremely well armed";
   if(wc > 25)
     return "Exceptionally well armed";
}

get_level_msg(lvl) {
   if(!lvl)
     return "You cannot determine the skill level";
   if(lvl <= 5)
     return "Poorly trained";
   if(lvl <= 10)
     return "Moderately well trained";
   if(lvl <= 15)
     return "Very well trained";
   if(lvl <= 20)
     return "Extremely well trained";
   if(lvl <= 30)
     return "Exceptionally well trained";
   if(lvl > 30)
     return "Unbelievably well trained. Attack with caution";
}

get_health_msg(hp,mhp) {
   int health;

   if(!hp || !mhp)
     return "You cannot determine your opponent's health";
   health = (hp*100)/(mhp);
   if(health >= 85)
     return "Excellent";
   if(health >=70)
     return "Good";
   if(health >= 50)
     return "Fair";
   if(health >= 30)
     return "Poor";
   if(health >= 15)
     return "Bad";
   return "On the verge of death";
}
