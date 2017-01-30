id(str){ return str == "damage_report_object" || str == "tester"; }

report_damage(dam){
 tell_object(environment(), "DAMAGE::: "+dam+"\n");
 if(previous_object())
 if(previous_object()->query_npc())
 tell_object(environment(), previous_object()->query_name()+"\n");
 return;
 }