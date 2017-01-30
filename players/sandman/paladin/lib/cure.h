
/*
 * CURE (2/11/94)
 * Some healing spells                            LEVEL   MAX HP   COST SP 
 *   cure_light_wounds    = piety + level           5       39       25
 *   cure_serious_wounds  = (piety + level) * 2     8       78       45
 *   cure_critical_wounds = (piety + level) * 4    12      156       75
 */

cure_light_wounds(str) {
   int heal, pie, lvl;
   object target;

   if(!verify_use("spell",5,25))
     return 1;
   if(!str)
     str = this_player()->query_real_name();
   target = find_player(str);
   if(!target || !present(target, environment(this_player())))
     notify_fail(capitalize(str)+" is not here.");
   pie = this_player()->query_attrib("pie");
   lvl = this_player()->query_level();
   heal = pie + lvl;
   do_heal(target,heal);
   return 1;
}

cure_serious_wounds(str) {
   int heal, pie, lvl;
   object target;

   if(!verify_use("spell",8,45)) 
     return 1;
   if(!str)
     str = this_player()->query_real_name();
   target = find_player(str);
   if(!target || !present(target, environment(this_player())))
     notify_fail(capitalize(str)+" is not here.");
   pie = this_player()->query_attrib("pie");
   lvl = this_player()->query_level();
   heal = (pie + lvl) * 2;
   do_heal(target,heal);
   return 1;
}   
   
cure_critical_wounds(str) {
   int heal, pie, lvl;
   object target;

   if(!verify_use("spell",12,75)) 
     return 1;
   if(!str)
     str = this_player()->query_real_name();
   target = find_player(str);
   if(!target || !present(target, environment(this_player())))
     notify_fail(capitalize(str)+" is not here.");
   pie = this_player()->query_attrib("pie");
   lvl = this_player()->query_level();
   heal = (pie + lvl) * 4; 
   do_heal(target,heal);
   return 1;
}   
   
do_heal(target,heal) {   
   target->add_hit_point(heal);
   TELL(capitalize(this_player()->query_name())+" casts a spell.\n");
   tell_object(target, "You feel better.\n");
   return 1;
}


